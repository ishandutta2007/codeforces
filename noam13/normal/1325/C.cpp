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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi ans(n-1,-1);
    vvi deg(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; a--;b--;
        deg[a].pb(i);
        deg[b].pb(i);
    }
    int p=-1;
    loop(i,0,n){
        if (deg[i].size()>2) p=i;
    }
    if (p==-1) {
        loop(i,0,n-1) cout<<i<<endl;
        return 0;
    }
    loop(i,0,3) ans[deg[p][i]]=i;
    int cnt=3;
    loop(i,0,n-1) if (ans[i]==-1) ans[i]=cnt++;
    loop(i,0,n-1) cout<<ans[i]<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
3
1 2
1 3

*/