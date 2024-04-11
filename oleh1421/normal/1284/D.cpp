//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=200001;
const long long mod=98232839193298231ll;
ll p[N];
int la[N];
int lb[N];
int ra[N];
int rb[N];
ll prefA[N];
ll prefB[N];
ll sufA[N];
ll sufB[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    p[0]=1ll;
    for (int i=1;i<=n;i++) p[i]=(p[i-1]*2ll)%mod;
    vector<pair<int,int> >x;
    vector<pair<int,int> >y;
    vector<pair<int,int> >z;
    vector<pair<int,int> >t;

    for (int i=1;i<=n;i++) cin>>la[i]>>ra[i]>>lb[i]>>rb[i],x.push_back({la[i],i}),y.push_back({ra[i],i}),z.push_back({lb[i],i}),t.push_back({rb[i],i});
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    sort(t.begin(),t.end());
    sufA[n+1]=0;
    for (int i=n;i>=1;i--){
        sufA[i]=(sufA[i+1]+p[x[i-1].second])%mod;
    }
    sufB[n+1]=0;
    for (int i=n;i>=1;i--){
        sufB[i]=(sufB[i+1]+p[z[i-1].second])%mod;
    }
    prefA[0]=0ll;
    for (int i=1;i<=n;i++){
        prefA[i]=(prefA[i-1]+p[y[i-1].second])%mod;
    }
    prefB[0]=0ll;
    for (int i=1;i<=n;i++){
        prefB[i]=(prefB[i-1]+p[t[i-1].second])%mod;
    }
    for (int i=1;i<=n;i++){
        pair<int,int>fnd;
        int pos;
        ll hashA=0ll;
        fnd={la[i],-1};
        pos=lower_bound(y.begin(),y.end(),fnd)-y.begin();
        hashA+=prefA[pos];
        fnd={ra[i],1000000001};
        pos=upper_bound(x.begin(),x.end(),fnd)-x.begin()+1;
        hashA+=sufA[pos];


        ll hashB=0ll;
        fnd={lb[i],-1};
        pos=lower_bound(t.begin(),t.end(),fnd)-t.begin();
        hashB+=prefB[pos];
        fnd={rb[i],1000000001};
        pos=upper_bound(z.begin(),z.end(),fnd)-z.begin()+1;
        hashB+=sufB[pos];
        hashA%=mod;
        hashB%=mod;
        if (hashA!=hashB){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}