//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=200010;
const ll mod=1000000007ll;
int w[N];
int x[N];
int y[N];
vector<int>g[N];
bool used[N];
int val[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        g[x[i]].push_back(i);
        g[y[i]].push_back(i);
    }
    for (int i=1;i<=n;i++){
        val[i]=w[i]-(int)g[i].size();
    }
    vector<int>ans;
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++){
        st.insert({val[i],i});
    }
    while (!st.empty()){
        int v=(*st.rbegin()).second;
        st.erase(--st.end());
//        cout<<v<<endl;
        if (val[v]<0){
            cout<<"DEAD\n";
            return;
        }
        for (auto ind:g[v]){
            if (used[ind]) continue;
            used[ind]=true;
            ans.push_back(ind);
            int to=x[ind];
            if (to==v) to=y[ind];
            st.erase({val[to],to});
            val[to]++;
            st.insert({val[to],to});
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"ALIVE\n";
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
}

int main()
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
/*
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
???????
*/