#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

int n,m,sn;
vvi g;
vi dep, last, take;
void dfs(int cur, int p=-1){
    dep[cur] = last.size(); last.pb(cur+1);
    for(auto nei:g[cur]){
        if (cur==p) continue;
        if (dep[nei]==-1){
            dfs(nei, cur);
        }
        else{
            if (dep[cur]-dep[nei]+1<sn) continue;
            cout<<2<<endl<<(dep[cur]-dep[nei]+1)<<endl;
            loop(i,dep[nei],dep[cur]+1) cout<<last[i]<<" ";
            cout<<endl;
            exit(0);
        }
    }
    if (!take[cur]){
        take[cur] = 2;
        for(auto nei:g[cur]) take[nei]=1;
    }
    last.pop_back();
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(sn=1;sn*sn<n;sn++);
    g.resize(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--;b--;
        g[a].pb(b); g[b].pb(a);
    }
    dep.resize(n,-1); take.resize(n,0);
    dfs(0);
    cout<<1<<endl;
    vi ind;
    loop(i,0,n) if (take[i]==2) ind.pb(i+1);
    if (ind.size()<sn) cout<<"FUCK";
    else loop(i,0,sn) cout<<ind[i]<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
6 6
1 3
3 4
4 2
2 6
5 6
5 1


*/