//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
const ll mod=998244353ll;
int c[N];
struct vertex{
    ll dp[2][2];
    int L,R;
};
vertex t[N*4];
vertex empt;
vertex marge(vertex a,vertex b){
    if (a.L==-1) return b;
    if (b.L==-1) return a;
    vertex res;
    res.L=a.L;
    res.R=b.R;
    ///calc dp[i][0]
    for (int i=0;i<2;i++){
        res.dp[i][0]=(a.dp[i][0]*b.dp[0][0]);
        if (c[a.R]==1) res.dp[i][0]+=(a.dp[i][1]*b.dp[c[a.R]][0]);
        res.dp[i][0]%=mod;
    }
    ///calc dp[i][1]
    for (int i=0;i<2;i++){
        res.dp[i][1]=(a.dp[i][0]*b.dp[0][1]);
        if (c[a.R]==1) res.dp[i][1]+=(a.dp[i][1]*b.dp[c[a.R]][1]);
        res.dp[i][1]%=mod;
    }
    return res;
}
void build(int v,int l,int r){
    if (l>r) return;
    if (l==r){
        t[v].L=l;
        t[v].R=r;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                t[v].dp[i][j]=0;
            }
        }
        for (int a=0;a<10;a++){
            for (int b=0;b<10;b++){
                int d1=(a+b)/10;
                int d2=(a+b)%10;
                if (d2!=c[l]) continue;
                t[v].dp[d1][0]++;
            }
        }
        t[v].dp[0][1]++;
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=marge(t[v+v],t[v+v+1]);
//    cout<<l<<" "<<r<<" "<<t[v].dp[0][0]<<endl;

}
void upd(int v,int l,int r,int pos,int d){
    if (l>pos || r<pos) return;
    if (l==r){
        c[pos]=d;
        t[v].L=l;
        t[v].R=r;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                t[v].dp[i][j]=0;
            }
        }
        for (int a=0;a<10;a++){
            for (int b=0;b<10;b++){
                int d1=(a+b)/10;
                int d2=(a+b)%10;
                if (d2!=c[l]) continue;
                t[v].dp[d1][0]++;
            }
        }
        t[v].dp[0][1]++;
        return;
    }
    int m=(l+r)/2;
    upd(v+v,l,m,pos,d);
    upd(v+v+1,m+1,r,pos,d);
    t[v]=marge(t[v+v],t[v+v+1]);
}
void solve(){
    empt.L=-1;
    int n,m;cin>>n>>m;
    c[0]=0;
    for (int i=1;i<=n;i++){
        char d;cin>>d;
        c[i]=(d-'0');
    }
    build(1,1,n);
//        cout<<t[1].dp[0][0]<<endl;

    for (int i=1;i<=m;i++){
        int pos,d;cin>>pos>>d;
        upd(1,1,n,pos,d);
        cout<<t[1].dp[0][0]<<endl;
    }

}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}