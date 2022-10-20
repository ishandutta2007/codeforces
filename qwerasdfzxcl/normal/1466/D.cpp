#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct vertex{
    ll val;
    int d;
    int num;
    vertex(){}
    vertex(ll _val, int _d, int _num){
        val=_val;
        d=_d;
        num=_num;
    }
    bool operator < (const vertex &v)const{
        return val<v.val;
    }
};
vertex deg[200200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        ll ans=0;
        for (int i=1;i<=n;i++) deg[i]=vertex(0, 0, 0);
        for (int i=1;i<=n;i++){
            scanf("%lld ", &deg[i].val);
            ans += deg[i].val;
            deg[i].num=i;
        }
        for (int i=0;i<n-1;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            deg[a].d++, deg[b].d++;
        }
        sort(deg+1, deg+n+1);
        int test=0;
        printf("%lld ", ans);
        for (int i=n;i>=1;i--){
            for (int j=0;j<deg[i].d-1;j++){
                ans += deg[i].val;
                printf("%lld ", ans);
                test++;
                if (test>=n-1) break;
            }
            if (test>=n-1) break;
        }
        printf("\n");
    }
    return 0;
}