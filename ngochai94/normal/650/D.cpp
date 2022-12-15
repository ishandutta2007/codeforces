#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a) for(int i=0;i<a;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

#define maxn 1000005

int n, m, c[maxn], a[maxn], b[maxn];
vector<int> VV;
vector<int> V[maxn];
int f[maxn], g[maxn];
int F[maxn], G[maxn];
int FF[maxn], GG[maxn];
int RR[maxn];
vector<int> d[maxn];
bool flag[maxn];

int get1(int u){
    int res = 0;
    for(int i = u; i > 0; i -= i & -i) res = max(res, f[i]);
    return res;
}

void update1(int u, int gt){
    for(int i = u; i < maxn; i += i & -i) f[i] = max(f[i], gt);
}

int get2(int u){
    int res = 0;
    for(int i = u; i < maxn; i += i & -i) res = max(res, g[i]);
    return res;
}

void update2(int u, int gt){
    for(int i = u; i > 0; i -= i & -i) g[i] = max(g[i], gt);
}

int main( ){
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    For(i,1,n) {
        cin >> a[i];
        VV.push_back(a[i]);
    }
    For(i,1,m){
        cin >> c[i] >> b[i];
        VV.push_back(b[i]);
    }
    sort(VV.begin(), VV.end());
    For(i,1,n) a[i] = lower_bound(VV.begin(), VV.end(), a[i]) - VV.begin() + 1;
    For(i,1,m) {
        b[i] = lower_bound(VV.begin(), VV.end(), b[i]) - VV.begin() + 1;
        V[c[i]].push_back(i);
    }

    memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
    memset(F, 0, sizeof(F)); memset(G, 0, sizeof(G));

    int res = 0;
    for(int i = 1; i <= n; i++){
        F[i] = get1(a[i] - 1) + 1;
        res = max(res, F[i]);
        update1(a[i], F[i]);
    }
    for(int i = n; i >= 1; i--){
        G[i] = get2(a[i] + 1) + 1;
        update2(a[i], G[i]);
    }

    for(int i = 1; i <= n; i++){
        if(F[i] + G[i] == res + 1){
            d[F[i]].push_back(i);
        }
    }

    memset(flag, 0, sizeof(flag));
    for(int i = 1; i <= res; i++) if((int)(d[i].size()) == 1){
       // cout << d[i][0] << endl;
        flag[d[i][0]] = 1;
    }

    memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
    memset(FF, 0, sizeof(GG)); memset(GG, 0, sizeof(GG));


    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (int)(V[i].size()); j++){
            int u = V[i][j];
            FF[u] = get1(b[u] - 1) + 1;
        }
        update1(a[i], F[i]);
    }

    for(int i = n; i >= 1; i--){
        for(int j = 0; j < (int)(V[i].size()); j++){
            int u = V[i][j];
            GG[u] = get2(b[u] + 1) + 1;
        }
        update2(a[i], G[i]);
    }

    for(int i = 1; i <= m; i++){
        //cout << FF[i] << " " << GG[i] << endl;
      //  cout << i << " " << a[i] << " " << flag[a[i]] << endl;
        if(FF[i] + GG[i] - 1 > res) cout << res + 1 << "\n";
        else if(FF[i] + GG[i] - 1 == res) cout << res << "\n";
        else{
            if(flag[c[i]]) cout << res - 1 << "\n";
            else cout << res << "\n";
        }
    }

}