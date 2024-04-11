#include <cstdio>
#include <queue>
using namespace std;

int main(void) {
    int n;
    scanf("%d\n",&n);
    bool arr[255];
    int count=0;
    for(int i=0;i<n;i++) {
        char x;
        scanf("%c",&x);
        if (x=='B') {
            arr[i]=true;
            count+=1;
        }
        else {
            arr[i]=false;
        }
    }
    bool target=false;
    if (n%2==0&&count%2==1) {
        printf("-1");
        return 0;
    }
    if (n%2==1&&count%2==1) {
        target=true;
    }
    queue<int> q;
    int ret=0;
    for(int i=0;i<n-1;i++) {
        if (arr[i]!=target) {
            arr[i]^=1;
            arr[i+1]^=1;
            q.push(i+1);
            ret+=1;
        }
    }
    printf("%d\n",ret);
    while (!q.empty()) {
        printf("%d ",q.front());
        q.pop();
    }
    return 0;
}