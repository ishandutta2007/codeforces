// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 

/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
/******************************/

const ll MAX = 2e5 + 5, oo = 1e12, MOD = 1e9 + 7;
ll n, m, color[MAX];
vector<ll>a[MAX];
vector<ii>e;
bool p;
/*********FUNCTIONS**************/
void dfs(int u, int c){
    color[u] = c;
    for(auto v : a[u])
        if(color[v] == -1)dfs(v, c ^ 1);
    else if( color[u] == color[v])p = false;
}
/***********MAIN**************/

int main(void) 
{
	cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v; a[u].push_back(v), a[v].push_back(u);
        e.push_back({u,v});
    }
    fill(color + 1, color + n + 1, -1);
    p = true;
    dfs(1,0);
    if(!p){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < m; i++) cout << (color[e[i].first] < color[e[i].second]);
	return 0;
}