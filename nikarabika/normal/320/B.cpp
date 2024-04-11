#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second
const int maxn = 1e2 + 10;
int n;
bool mark[maxn];
vector<int> v[maxn];
vector<pair<int, int> > in;

void dfs(int x){
	mark[x] = true;
	for(int i = 0; i < v[x].size(); i++)
		if(!mark[v[x][i]])
			dfs(v[x][i]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	while(n--){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		if(ty == 1){
			in.PB(MP(fi, se));
			for(int i = 0; i + 1 < in.size(); i++){
				int c = in[i].L, d = in[i].R;
				if((fi > c and fi < d) or (se > c and se < d))
					v[in.size()].PB(i + 1);
				if((c > fi and c < se) or (d > fi and d < se))
					v[i + 1].PB(in.size());
			}
		}
		else{
			memset(mark, false, sizeof mark);
			dfs(fi);
			cout << (mark[se] ? "YES\n" : "NO\n");
		}
	}
	return 0;
}