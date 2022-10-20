#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int sparse[300300][20];
ll a[300300], c[300300];
bool chk[300300];

int query(int v){
    for (int i=19;i>=0;i--) if (sparse[v][i]!=-1 && !chk[sparse[v][i]]){
        v = sparse[v][i];
    }
    if (chk[v]) return -1;
    return v;
}

int main(){
    int q;
    scanf("%d %lld %lld", &q, a, c);
    for (int i=0;i<=q;i++) fill(sparse[i], sparse[i]+20, -1);
    for (int cur=1;cur<=q;cur++){
        int t;
        scanf("%d", &t);
        if (t==1){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            a[cur] = y, c[cur] = z;
            sparse[cur][0] = x;
            for (int i=1;i<20 && sparse[cur][i-1]!=-1;i++) sparse[cur][i] = sparse[sparse[cur][i-1]][i-1];
        }
        else{
            int v;
            ll w;
            scanf("%d %lld", &v, &w);
            ll cnt = 0, cst = 0;
            while(w){
                int x = query(v);
                if (x==-1) break;
                ll tmp = min(a[x], w);
                w -= tmp;
                cnt += tmp;
                cst += tmp*c[x];
                a[x] -= tmp;
                if (!a[x]) chk[x] = 1;
            }
            printf("%lld %lld\n", cnt, cst);
            fflush(stdout);
        }
    }
    return 0;
}