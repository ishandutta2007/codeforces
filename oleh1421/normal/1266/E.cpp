#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
int cnt[300001];
int a[300001];
ll res=0;
void inc(int x){
    cnt[x]++;
    if (cnt[x]<=a[x]) res--;
}
void dec(int x){
    if (cnt[x]<=a[x]) res++;
    cnt[x]--;
}
map<pair<int,int>,int>mp;
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],res+=a[i]*1ll;
    int tt;cin>>tt;
    while (tt--){
        int s,t,x;cin>>s>>t>>x;
        if (mp[{s,t}]) dec(mp[{s,t}]);
        inc(x);
        mp[{s,t}]=x;
        cout<<res<<endl;
    }

    return 0;
}