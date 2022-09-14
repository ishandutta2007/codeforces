#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100000;
int a[200001];
bool used[200001];
map<vector<pair<int,int> >,int>mp;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=N;i++) used[i]=true;
    for (int i=2;i*i<=N;i++){
        if (used[i]){
            for (int j=i*i;j<=N;j+=i) used[j]=false;
        }
    }
    vector<int>p;
    for (int i=2;i<=N;i++){
        if (used[i]) p.push_back(i);
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        int d=0;
        int cur=a[i];
        vector<pair<int,int> >x;
        vector<pair<int,int> >y;
        while (d<p.size() && p[d]*p[d]<=cur){
            int cnt=0;
            while ((cur%p[d])==0){
                cur/=p[d];
                cnt++;
            }
            cnt%=k;
            if (cnt) {
                x.push_back({p[d],cnt});
                y.push_back({p[d],k-cnt});
            }
            d++;
        }
        if (cur>1){
            x.push_back({cur,1});
            y.push_back({cur,k-1});
        }
        res+=mp[y]*1ll;
        mp[x]++;

    }
    cout<<res;
    return 0;
}