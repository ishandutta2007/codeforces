#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

long long arr[100000];
typedef pair<int,int> P;
typedef pair<P,long long> Pl;

int main(void) {
    int n,m;
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<m;i++) {
        int a,b;
        long long d;
        scanf("%d %d %lld",&a,&b,&d);
        a--;
        b--;
        arr[a]-=d;
        arr[b]+=d;
    }
    int p=0;
    int ret=0;
    queue<Pl> q;
    for(int i=0;i<n;i++) {
        while (arr[i]<0) {
            if (arr[p]>0) {
                q.push(Pl(P(i+1,p+1),min(-arr[i],arr[p])));
                long long amount=min(-arr[i],arr[p]);
                arr[i]+=amount;
                arr[p]-=amount;
                ret+=1;
            }
            if (arr[p]<=0) {
                p++;
            }
        }
    }
    printf("%d\n",ret);
    while (!q.empty()) {
        printf("%d %d %lld\n",q.front().first.first,q.front().first.second,q.front().second);
        q.pop();
    }
    return 0;
}