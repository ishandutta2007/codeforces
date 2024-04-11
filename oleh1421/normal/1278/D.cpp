#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007ll;
typedef long long ll;
using namespace std;
vector<int>g[600001];
bool used[600001];
void dfs(int v){
    used[v]=true;
    for (auto to:g[v]){
        if (!used[to]) dfs(to);
    }
}
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<pair<int,int> >v;
 
    for (int i=1;i<=n;i++) {
        int l,r;cin>>l>>r;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());
    set<pair<int,int> >st;
    int cnt=0;
    for (int i=0;i<n && cnt<n;i++){
        auto l=st.lower_bound({v[i].first,-1});
        auto r=st.lower_bound({v[i].second,-1});
        for (auto it=l;it!=r;it++){
            cnt++;
            g[i+1].push_back((*it).second+1);
            g[(*it).second+1].push_back(i+1);
        }
        st.insert({v[i].second,i});
    }
    if (cnt>=n){
        cout<<"NO";
        return 0;
    }
    dfs(1);
    for (int i=1;i<=n;i++){
        if (!used[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}