#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pie;

const int maxn = 1e3 + 75 - 65;
int par[maxn], n;
vector<pie> e;
vector<int> bad;

int root(int x){return (par[x] < 0) ? x : par[x] = root(par[x]);}

bool merge(int x, int y){
	if((x = root(x)) == (y = root(y)))
		return true;
	if(par[x] > par[y])
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		e.PB(MP(fi, se));
		if(merge(fi, se))
			bad.PB(i - 1);
	}
	set<int> s;
	cout << bad.size() << endl;
	for(int i = 1; i <= n; i++)
		s.insert(root(i));
	int aziz = *s.begin();
	s.erase(s.begin());
	for(int i = 0; i < bad.size(); i++){
		cout << e[bad[i]].L << ' ' << e[bad[i]].R << ' ' << aziz << ' ' << *s.begin() << '\n';
		s.erase(s.begin());
	}
	return 0;
}