#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second
#define X first.second
#define Y first.first
#define MP make_pair
#define MYP(aa, bb, cc) MP(MP(bb, aa), cc)
#define PB push_back

typedef pair<pair<int, int>, int> myp;
typedef long long int ll;

const int maxn = 1e5 + 10;
myp a[maxn];
vector<int> par[maxn], ch[maxn], adj[maxn];
bool mark[maxn];
int n;
ll ans = 0, D = 1e9 + 9;
set<int> s;

bool isncut(int v){
	for(int i = 0; i < ch[v].size(); i++) if(!mark[ch[v][i]]){
		int c = 0,
			u = ch[v][i];
		for(int j = 0; j < par[u].size(); j++)
			if(!mark[par[u][j]])
				c++;
		if(c <= 1)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].X >> a[i].Y;
		a[i].R = i + 1;
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		int v = a[i].R,
			xv = a[i].X,
			yv = a[i].Y;
		myp *Ptr = lower_bound(a, a + n, MYP(xv - 1, yv + 1, -1));
		while(Ptr < a + n and Ptr->Y == yv + 1 and Ptr->X <= xv + 1){
			int u = Ptr->R;
			par[u].PB(v);
			ch[v].PB(u);
			Ptr++;
		}
		Ptr = lower_bound(a, a + n, MYP(xv - 2, yv, -1));
		while(Ptr < a + n and Ptr->Y == yv and Ptr->X <= xv + 2){ 
			if(Ptr->X != xv)
				adj[v].PB(Ptr->R);
			Ptr++;
		}
	}
	//find free(s)
	for(int i = 0; i < n; i++){
		int v = a[i].R;
		if(isncut(v))
			s.insert(v);
	}
	bool turn = false;
	while(s.size()){
		int v;
		if(turn){
			v = *s.begin();
			s.erase(s.begin());
		}
		else{
			set<int>::iterator it = s.end();
			it --;
			v = *it;
			s.erase(it);
		}
		mark[v] = true;
		ans = (ans * (ll)n) % D;
		ans = (ans + (ll)(v - 1)) % D;

		for(int i = 0; i < par[v].size(); i++) if(!mark[par[v][i]]){
			if(isncut(par[v][i]))
				s.insert(par[v][i]);
			else
				s.erase(par[v][i]);
		}

		for(int i = 0; i < adj[v].size(); i++) if(!mark[adj[v][i]]){
			if(isncut(adj[v][i]))
				s.insert(adj[v][i]);
			else
				s.erase(adj[v][i]);
		}

		for(int i = 0; i < ch[v].size(); i++) if(!mark[ch[v][i]]){
			if(isncut(ch[v][i]))
				s.insert(ch[v][i]);
			else
				s.erase(ch[v][i]);
		}
		turn = !turn;
	}
	cout << ans << endl;
	return 0;
}