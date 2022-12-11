#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<pii> T[N];

struct Edge{
	int ue;
	int ve;
	int wei;
	bool operator<(Edge A){
		return wei < A.wei;
	}
};

int pi[N];
int sz[N];
int x[N];

void init(){
	for(int i = 0 ; i < N ;i ++ ){
		pi[i] = i;
		sz[i] = 1;
	}
}

int fin(int a){
	if(pi[a] == a)
		return a;
	return pi[a] = fin(pi[a]);
}

bool merge(int a, int b){
	a = fin(a);
	b = fin(b);
	if(a == b)
		return false;
	if(sz[a] > sz[b])
		swap(a, b);
	sz[b] += sz[a];
	x[b] += x[a];
	pi[a] = b;
	return true;
}

int ans = 0;
int k;

int main(){
	fastIO;
	init();
	int n, m;
	cin >> n >> m >> k;
	int c;
	for(int i = 0 ;i < k ; i ++ ){
		cin >> c;
		x[c] = 1;
	}
	Edge eg[m];
	for(int i = 0; i < m ; i ++ ){
		cin >> eg[i].ue >> eg[i].ve >> eg[i].wei;
	}
	sort(eg, eg + m);
	int tu, tv;
	for(int i = 0 ; i < m;i ++ ){
		tu = eg[i].ue;
		tv = eg[i].ve;
		if(merge(tu, tv)){
			if(x[fin(tu)] == k){
				ans = eg[i].wei;
				break;
			}
		}
	}
	for(int t = 1; t <= k ; t ++ ){
		cout << ans << " ";
	}
	return 0;
}