#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct node{
    ll w;
    int deg;
    bool operator < (const node &O ) const{ return w > O.w; }
};

node ver[100002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        ll sum = 0;

        for(int i=1;i<=n;i++){
            scanf("%lld", &ver[i].w);
            sum += ver[i].w;
            ver[i].deg = 0;
        }

        for(int i=1;i<n;i++){
            int s, e;
            scanf("%d %d", &s, &e);
            ver[s].deg++;
            ver[e].deg++;
        }

        sort(ver+1, ver+n+1);

        int curr = 1;

        for(int i=1;i<=n-2;i++){
            printf("%lld ", sum);
            while(ver[curr].deg == 1){
                curr++;
            }
            sum += ver[curr].w;
            ver[curr].deg--;
        }
        printf("%lld\n", sum);
    }
}