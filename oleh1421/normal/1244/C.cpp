#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int long long
int binpow(int a,int b,int mod){
    if (b==0) return 1ll;
    if (b%2) return (a*binpow(a,b-1ll,mod))%mod;
    else return binpow((a*a)%mod,b/2ll,mod);
}
int32_t main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int n,p,w,d;cin>>n>>p>>w>>d;
    int g=__gcd(w,d);
    if (p%g){
        cout<<-1;
        return 0;
    }
    for (int y=0;y<w && y*d<=p && y<=n;y++){
        if ((p-y*d)%w) continue;
        int x=(p-y*d)/w;
        if (x+y<=n){
            cout<<x<<" "<<y<<" "<<n-x-y;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
  /*  int n,k;cin>>n>>k;
    set<int>st;
    int minx=100000001;
    int maxx=-1;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
        st.insert(x);
        minx=min(minx,x);
        maxx=max(maxx,x0)
    }
    vector<int>v;
    for (auto i:st) v.push_back(i);*/