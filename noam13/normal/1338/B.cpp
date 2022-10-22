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
const int INF = 1e18, MOD = 1e9+7;

int n;
vvi g;
vi h;
int dfs(int cur, int p=-1){
	
	h[cur] = 0;
	for(auto nei:g[cur]) if (nei!=p){
		chkmax(h[cur],dfs(nei, cur)+1);
	}
	//cout<<"DFS: "<<cur<<" "<<h[cur]<<endl;
	return h[cur];
}
bool canone = 1;
void mini(int cur, int p=-1, int d=0){
	if (h[cur]==0){
		if (d%2) canone = 0;
		return ;
	}
	for(auto nei:g[cur]) if (nei!=p){
		mini(nei, cur, d+1);
	}
}
int maxans = 0;
void maxi(int cur, int p=-1, int d=0){
	//cout<<"VISIT: "<<cur<<endl;
	bool hasone = 0;
	for(auto nei:g[cur]) if (nei!=p){
		if (h[nei]==0){
			hasone = 1; continue;
		}
		maxans++; maxi(nei, cur, d+1);
	}
	if (d!=1) maxans+=hasone;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n; g = vvi(n);
    loop(i,0,n-1){
    	int a,b; cin>>a>>b; a--; b--;
    	g[a].pb(b); g[b].pb(a);
    }
    int root = -1;
    loop(i,0,n) if(g[i].size()==1) root = i;
    
    h = vi(n,-1);
    dfs(root);
    //cout<<"ROOT: "<<root<<" "<<h[root]<<endl;
    mini(root);  maxi(root);
    cout<<(canone?1:3)<<" "<<maxans<<endl;
    

    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
6
1 3
2 3
3 4
4 5
5 6


*/