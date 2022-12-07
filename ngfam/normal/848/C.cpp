#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 12800005;

int val[N];
int n, m;

struct SegmentTree2D{

	int cnt;
	int root[M];
	long long value[M];
	int Ls[M], Rs[M];

	#define mid ((l + r) >> 1)

	void update(int &i, int l, int r, int x, int val){
		if(l > x || r < x){
			return;
		}
		if(i == 0){
			i = ++cnt;
		}
		value[i] += val;
		if(l == r){
			return;
		}
		update(Ls[i], l, mid, x, val);
		update(Rs[i], mid + 1, r, x, val);
	}

	void upd(int i, int x, int val){
		for(; i < N; i += i & -i){
			update(root[i], 1, n, x, val);
		}
	}

	long long qr(int i, int l, int r, int x, int y){
		if(i == 0 || l > y || r < x){
			return 0;
		}
		if(l >= x && r <= y){
			return value[i];
		}
		return qr(Ls[i], l, mid, x, y) + qr(Rs[i], mid + 1, r, x, y);
	}

	long long ask(int i, int x, int y){
		long long ans = 0;
		for(; i; i &= i - 1){
			ans += qr(root[i], 1, n, x, y);
		}
		return ans;
	}

	long long Range(int l, int r, int x, int y){
		return ask(r, x, y) - ask(l - 1, x, y);
	}
}Smt;
	int sz = 0;
	int rt = 1;

int a[N];
int last[N];
set < int > pos[N];
set < int > :: iterator it, lol, ins;


void Add(int val, int u, int v){
	Smt.upd(u, v, val);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}


	scanf("%d%d", &n, &m);


	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if(last[a[i]] != 0){
			Add(i - last[a[i]], last[a[i]], i);
			val[i] = i - last[a[i]];
		}
		last[a[i]] = i;
		pos[a[i]].insert(i);
	}

	//cout << "?" << endl;


	for(int i = 1; i <= m; ++i){
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);

		//cout << i << " " << pos[3].size() << endl;

		if(t == 2){
			printf("%lld\n", Smt.Range(u, v, u, v));
		}
		else{
			//cout << pos[3].size() << endl;
			it = pos[a[u]].lower_bound(u);
			assert(it != pos[a[u]].end());
			++it;
			ins = it;
			--it;
		//	cout << pos[a[u]].size() << endl;
			if(pos[a[u]].size() != 1){
				if(it != pos[a[u]].begin()){
					--it;
					lol = it;
					++it;
					Add(*lol - *it, *lol, *it);
					if(ins != pos[a[u]].end()){
						Add(*it - *ins, *it, *ins);
						Add(*ins - *lol, *lol, *ins);
					}
				}
				else if(ins != pos[a[u]].end()){
					Add(*it - *ins, *it, *ins);
				}
			}
			pos[a[u]].erase(it);


			it = pos[v].lower_bound(u);


			if(pos[v].size() != 0){
				if(it != pos[v].end()){
					if(it != pos[v].begin()){
						--it;
						ins = it;
						++it;
						Add(*ins - *it, *ins, *it);
						Add(u - *ins, *ins, u);
					}
					Add(*it - u, u, *it);
				}
				else{
					assert(it != pos[v].begin());
					--it;
					Add(u - *it, *it, u);
				}
			}
			a[u] = v;
		pos[v].insert(u);
		}
		
	}	




	return 0;
}