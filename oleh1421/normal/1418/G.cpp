#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
mt19937_64 rnd(time(NULL));
ll pw[N];
ll cnt[N];
int a[N];
map<ll,ll>mp;
deque<int>g[N];
ll pref[N];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]--;
    pw[0]=1ll;
    pw[1]=3ll;
    ll mod=rnd()%(1ll<<60);
    while (mod%3ll==0 || mod%2ll==0) mod=rnd()%(1ll<<60);
    for (int i=2;i<=n;i++){
        pw[i]=(pw[i-1]*pw[1])%mod;
    }
    ll cur=0ll;
    mp[cur]++;
    ll res=0ll;
    int L=0;
    pref[0]=cur;

    for (int i=1;i<=n;++i){
        if (g[a[i]].size()<3){
            g[a[i]].push_back(i);
            cur+=mod-(pw[a[i]]*cnt[a[i]])%mod;
            cur%=mod;
            cnt[a[i]]++;
            cnt[a[i]]%=3;
            cur+=(pw[a[i]]*cnt[a[i]])%mod;
            cur%=mod;
            res+=(mp[cur]++);
        } else {
//            cout<<"OK "<<i<<" "<<res<<endl;
            int nxt=g[a[i]].front();
            for (int j=L+1;j<=nxt;j++){
                mp[pref[j-1]]--;
                g[a[j]].pop_front();
            }
            g[a[i]].push_back(i);
            L=nxt;
            cur+=mod-(pw[a[i]]*cnt[a[i]])%mod;
            cur%=mod;
            cnt[a[i]]++;
            cnt[a[i]]%=3;
            cur+=(pw[a[i]]*cnt[a[i]])%mod;
            cur%=mod;
//            cout<<cur<<endl;
            res+=(mp[cur]++);
        }
        pref[i]=cur;
    }
    cout<<res<<endl;
    return 0;
}