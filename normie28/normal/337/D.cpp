#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,n) for(int i=0;i<n;i++)
const int MAX_NODES = 100010; 
 
int in[MAX_NODES]; 
int out[MAX_NODES]; 
vector<int> v[100010]; 
set<int> p;
int res=0;
int d;
 
void dfs1( int u, int parent) 
{ 
	in[u] = INT_MIN; 
	if(p.count(u)>0)
	in[u]=0;
 
	for (int child : v[u]) { 
 
		if (child == parent) 
			continue; 
 
		dfs1( child, u); 
 
		in[u] = max(in[u], 1 + in[child]); 
	} 
} 
 
void dfs2( int u, int parent) 
{ 
	int mx1 = INT_MIN, mx2 = INT_MIN; 
 
	for (int child : v[u]) { 
		if (child == parent) 
			continue; 
 
		if (in[child] >= mx1) { 
			mx2 = mx1; 
			mx1 = in[child]; 
		} 
 
		else if (in[child] > mx2) 
			mx2 = in[child]; 
	} 
 
	for (int child : v[u]) { 
		if (child == parent) 
			continue; 
 
		int longest = mx1; 
 
		if (mx1 == in[child]) 
			longest = mx2; 
 
		out[child] = 1 + max(out[u], 1 + longest); 
 
		dfs2( child, u); 
	} 
} 
 
void printHeights( int n) 
{ 
	dfs1(1, 0); 
 
	dfs2( 1, 0); 
	for (int i = 1; i <= n; i++) {
 
			if(d>=max(in[i], out[i])&&max(in[i], out[i])>=0 )
			res++;
	}
} 
 
int main() 
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n = 11; 
	int nb_p;
	cin>>n>>nb_p>>d;
	int x;
	
    rep(i,nb_p)
    cin>>x,p.insert(x);
    if(p.count(1)==0)
    out[1]=INT_MIN;
    rep(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        v[b].push_back(a), v[a].push_back(b); 
        
    }
 
 
	printHeights(n); 
	cout<<res<<endl;
}