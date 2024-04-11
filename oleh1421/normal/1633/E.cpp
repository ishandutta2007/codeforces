#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=310;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
int v[N],u[N],w[N];
ll sum[N*N];
ll c[N*N];
int dsu[N];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
 vector<int>x;
ll ans(int q){
    int ind=lower_bound(x.begin(),x.end(),q)-x.begin();
    return sum[ind]+c[ind]*q;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>v[i]>>u[i]>>w[i];
    }

    for (int i=1;i<=m;i++){
        x.push_back(w[i]);
    }
    x.push_back(0);
    x.push_back(1000000001);
    for (int i=1;i<=m;i++){
        for (int j=i+1;j<=m;j++){
            if ((w[i]+w[j])%2) x.push_back((w[i]+w[j])/2);
            else {
                x.push_back((w[i]+w[j])/2);
                x.push_back((w[i]+w[j])/2-1);

            }
        }
    }
    sort(x.begin(),x.end());
    for (int it=0;it<x.size();it++){
        vector<pair<int,int> >E;
        for (int i=1;i<=m;i++) E.push_back({abs(w[i]-x[it]),i});
        sort(E.begin(),E.end());
        for (int i=1;i<=n;i++) dsu[i]=i;
        for (auto cur:E){
            int ind=cur.second;
            int a=get(u[ind]);
            int b=get(v[ind]);
            if (a!=b){
                dsu[a]=b;
                if (w[ind]<x[it]){
                    sum[it]-=w[ind];
                    c[it]++;
                } else {
                    sum[it]+=w[ind];
                    c[it]--;
                }
            }
        }
    }
    ll p,k,a,b,c;cin>>p>>k>>a>>b>>c;
    ll last;
    ll res=0ll;
    for (int i=1;i<=p;i++){
        cin>>last;
        res^=ans(last);
    }

    for (int i=p+1;i<=k;i++){
        last=(last*a+b)%c;
        res^=ans(last);
    }
    cout<<res<<endl;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}