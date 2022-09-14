#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
int a[300001];
int f[300001];
vector<int>g[33];
map<vector<int>,int>mp;
vector<pair<vector<int>,int> >v;
vector<int>cur;
int br=0;
int n;
void F(int pos,int mask){
    if (pos==br){
        v.push_back({cur,mask});
        return;
    }
    F(pos+1,mask);
   // if (g[pos].empty() || g[pos].size()==n) return;
    for (auto to:g[pos]) cur[to]++;
    F(pos+1,(mask^(1<<pos)));
    for (auto to:g[pos]) cur[to]--;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) f[i]=__builtin_popcount(a[i]);
    set<int>st;
    for (int i=1;i<=n;i++) st.insert(f[i]%2);
    if (st.size()==2){
        cout<<-1;
        return 0;
    }
    for (int i=1;i<=n;i++) f[i]/=2;
    for (int i=1;i<=n;i++){
        for (int j=0;j<30;j++){
            if (a[i]&(1<<j)) continue;
            g[j].push_back(i-1);
        }
    }
    cur.resize(n);
    for (int i=0;i<n;i++) cur[i]=0;
    br=15;
    F(0,0);
    for (auto cur:v){
        mp[cur.first]=cur.second;
    }
    for (int i=0;i<n;i++) cur[i]=0;
    br=30;
    F(15,0);
    for (auto x:v){
        vector<int>cur=x.first;
        /*for (auto i:cur) cout<<i<<" ";
        cout<<endl;*/
        int mask=x.second;
        for (int t=0;t<=30;t++){
            vector<int>to(n,t);
            for (int i=0;i<n;i++) to[i]-=f[i+1]+cur[i];
            if (mp.find(to)!=mp.end()){
                cout<<(mask^mp[to]);
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}