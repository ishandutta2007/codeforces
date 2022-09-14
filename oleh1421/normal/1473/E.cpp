//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
vector<pair<int,ll> >g[N*4];
ll d[N*4];
const ll inf=1000000000000000001ll;
bool used[N*5];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;
        b--;
        for (int mask=0;mask<4;mask++){
            if ((mask&1)==0){
                g[a*4+mask].push_back({b*4+mask+1,c*2});
            }
            if ((mask&2)==0){
                g[a*4+mask].push_back({b*4+mask+2,0});
            }
            g[a*4+mask].push_back({b*4+mask,c});
        }
        swap(a,b);
        for (int mask=0;mask<4;mask++){
            if ((mask&1)==0){
                g[a*4+mask].push_back({b*4+mask+1,c*2});
            }
            if ((mask&2)==0){
                g[a*4+mask].push_back({b*4+mask+2,0});
            }
            g[a*4+mask].push_back({b*4+mask,c});
        }
    }
    d[0]=0;
    for (int i=1;i<4*n;i++) d[i]=inf;
    set<pair<ll,int> >st;
    for (int i=0;i<4*n;i++){
        st.insert({d[i],i});
    }
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        if (used[v]) exit(1);
        used[v]=true;
        for (auto cur:g[v]){
            int to=cur.first;
            ll w=cur.second;
            if (d[v]+w<d[to]){
                st.erase({d[to],to});
                d[to]=d[v]+w;
                st.insert({d[to],to});
            }
        }
    }
    for (int i=1;i<n;i++){
        cout<<min(d[i*4],d[i*4+3])<<" ";
    }
    cout<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*


*/