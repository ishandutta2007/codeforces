#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d ",&x);
            if (x%2==0) {
                pq.push(x);
            }
        }
        scanf("\n");
        int ret=0;
        while (!pq.empty()) {
            int curr=pq.top();
            while (!pq.empty()&&pq.top()==curr) {
                pq.pop();
            }
            if ((curr/2)%2==0) {
                pq.push(curr/2);
            }
            ret+=1;
        }
        printf("%d\n",ret);
    }
    return 0;
}