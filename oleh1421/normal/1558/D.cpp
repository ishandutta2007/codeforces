
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000100;
const ll mod=998244353;
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
int x[N],y[N];
int t[N];
void upd(int pos,int x){
    for (;pos<N;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
int find_kth(int k){
    int pos=0;
    for (int i=20;i>=0;i--){
        if (pos+(1<<i)>=N) continue;
        if (pos+(1<<i)-get(pos+(1<<i))<k) pos+=(1<<i);
    }
    return pos+1;
}

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>x[i]>>y[i];
    for (int i=m;i>=1;i--){
        y[i]=find_kth(y[i]);
        upd(y[i],1);
    }
    for (int i=1;i<=m;i++) upd(y[i],-1);
//    for (int i=1;i<=m;i++){
//        for (int j=1;j<i;j++){
//            if (y[j]>=y[i]) y[j]++;
//        }
//    }
    vector<pair<int,int> >v;
    for (int i=1;i<=m;i++){
        v.push_back({y[i],x[i]});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<m;i++){
        x[i+1]=v[i].second;
        y[i+1]=v[i].first;
    }
//    for (int i=1;i<=m;i++) cout<<x[i]<<" "<<y[i]<<endl;
    int cnt=0;
    for (int i=1;i<=m;i++){
        int last;
        if (i>1 && y[i-1]+1==y[i]) last=x[i-1];
        else last=find_kth(y[i]-i);
        upd(x[i],1);
        if (last>x[i]) cnt++;
        if ((i<m && y[i+1]-1==y[i]) || y[i]==n) continue;

        int nxt=find_kth(y[i]-i+1);
        if (x[i]>nxt) cnt++;
    }
    for (int i=1;i<=m;i++) upd(x[i],-1);
    cout<<f[n*2-cnt-1]*rf[n]%mod*rf[n-cnt-1]%mod<<endl;
}
int32_t main()
{
    f[0]=1;
    for (int i=1;i<N;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[N-1]=binpow(f[N-1],mod-2);
    for (int i=N-1;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
//1 3 3 4
//0 1 2 3