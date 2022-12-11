#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = (int)2e5 + 9;
vector<int>G[N];

int col[N]; // biparite colors

void dfs(int u,int h){
	col[u] = h+1;
	h ^= 1;
	for(auto x : G[u]){
		if(col[x] == -1)
			dfs(x,h);
	}
}

int main(){
	fastIO;
	for(int i = 0;i<N;i++)
		col[i] = -1; // init
	int n;
	cin >> n;
	int a[n],b[n];
	int l,r;
	for(int i= 0;i<n;i++){
		cin >> a[i] >>b[i];
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
		l = i*2 + 2;
		r = l + 1;
		G[l].push_back(r);
		G[r].push_back(l);
	}
	for(int i = 1;i<=n*2+1;i++)
		if(col[i] == -1)
	dfs(i,1);
	for(int i = 0;i<n;i++)
		cout << col[a[i]] << " " << col[b[i]] << "\n";
	return 0;
}