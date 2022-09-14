//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000010;
int val[N];
int t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=val[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=max(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int> >a(n+1);
    for (int j=0;j<=n;j++) a[j].resize(m+1,0);
    vector<vector<int> >dp1=a;
    vector<vector<int> >dp2=a;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='.');
            dp1[i][j]=i;
            dp2[i][j]=j;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i-1][j]){
                dp1[i][j]=min(dp1[i][j],dp1[i-1][j]);
                dp2[i][j]=min(dp2[i][j],dp2[i-1][j]);
            }
            if (a[i][j-1]){
                dp1[i][j]=min(dp1[i][j],dp1[i][j-1]);
                dp2[i][j]=min(dp2[i][j],dp2[i][j-1]);
            }
        }
    }
//    vector<int>val(m+1,0);
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (dp1[j][i]==1) continue;
            val[i]=max(val[i],dp2[j][i]);
        }
    }
    build(1,1,m);
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        int x1,x2;cin>>x1>>x2;
        int mx=get(1,1,m,x1,x2);
//        for (int j=x1;j<=x2;j++){
//            mx=max(mx,val[j]);
//        }
        if (mx>x1){
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1 3
0.0 0.1 0.5 0.2
**/