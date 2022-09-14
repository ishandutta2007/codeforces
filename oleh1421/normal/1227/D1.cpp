//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
map<int,int>mp;
int val[300001];
set<int>g[300001];
int ans[300001];
bool used[300001];
void solve(){
    vector<pair<pair<int,int>,int> >q;
    int n;cin>>n;
    vector<int>v;
    for (int i=1;i<=n;i++) cin>>a[i],v.push_back(a[i]);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        int k,pos;cin>>k>>pos;
        for (int i=1;i<=n;i++) used[i]=false;
        vector<int>cur;
        int maxx=0;
        for (int j=1;j<=k;j++){
            int pos=-1;
            for (int t=maxx+1;t<=n;t++){
                if (a[t]==v[k-j]){
                    pos=t;
                    break;
                }
            }
            if (pos!=-1){
                cur.push_back(pos);
                maxx=pos;
                used[pos]=true;
                continue;
            }
            for (int t=maxx;t>=1;t--){
                if (used[t]) continue;
                if (a[t]==v[k-j]){
                    pos=t;
                    break;
                }
            }
            cur.push_back(pos);
            used[pos]=true;
        }
        sort(cur.begin(),cur.end());
        cout<<a[cur[pos-1]]<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}