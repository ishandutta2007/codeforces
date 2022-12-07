#include <bits/stdc++.h>

using namespace std;

const int N = 333000;
int n;

template < class Integer > 
class PersisdentSegementree{
	private :
		Integer value[N * 30];
		int cnt, L[N * 30], R[N * 30];
		
		Integer Merge(Integer x, Integer y){
			/// Insert Something here
			return max(x, y);
		} 		

		vector < pair < Integer, int > > lst;
	public : 

	#define mid ((l + r) >> 1)
	#define ii (i << 1)

	int root;

	void Initilize(){
		cnt = root = 1;
		memset(value, 0, sizeof value);
	}

	void Build(int node, int l, int r){
		if(l == r){
			return;
		}
		L[node] = ++cnt;
		R[node] = ++cnt;
		Build(L[node], l, mid);
		Build(R[node], mid + 1, r);
	}

	int upd(int node, int l, int r, int x, Integer val){
		if(l > x || r < x){
			return node;
		}
		int ans = ++cnt;
		
		if(l == r){
			value[ans] = Merge(value[node], val);
			return ans;
		}

		L[ans] = upd(L[node], l, mid, x, val);
		R[ans] = upd(R[node], mid + 1, r, x, val);
		value[ans] = Merge(value[L[ans]], value[R[ans]]);
		return ans;
	}

	Integer Query(int node, int l, int r, int x, int y){
		if(y < l || x > r){
			return 0;
		}
		if(l >= x && r <= y){
			return value[node];
		}
		return Merge(Query(L[node], l, mid, x, y), Query(R[node], mid + 1, r, x, y));
	}

	void Add(Integer X){
		lst.push_back(make_pair(X, root));
	}

	void update(int x, Integer val){
		root = upd(root, 1, n, x, val); 
	}

	Integer ask(Integer x, int l, int r){
		int f = upper_bound(lst.begin(), lst.end(), make_pair(x, root + 10)) - lst.begin() - 1;
		if(f == -1){
			return 0;
		}
		return Query(lst[f].second, 1, n, l, r);
	}

	Integer range(int l, int r, int x, int y){ /// 2D Only
		if(r < l || x > y){
			return 0;
		}
		return ask(r, x, y) - ask(l - 1, x, y);
	}
};


PersisdentSegementree < int > red;
PersisdentSegementree < int > blue;

int cnt[N][3];
vector < int > g[3];
pair < int, int > a[N];

#define s(i) (cnt[n][i])

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	vector < int > pos;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int x;
		char read[5];
		scanf("%d%s", &x, read);
		a[i].first = x;

		a[i].second = (read[0] == 'G' ? 0 : (read[0] == 'R' ? 1 : 2));

		if(a[i].second == 0) pos.push_back(i);

		++cnt[i][a[i].second];
		for(int j = 0; j < 3; ++j){
			cnt[i][j] += cnt[i - 1][j];
		}

		g[a[i].second].push_back(a[i].first);
	}


	long long ans = 0;

	if(s(0) == 0){
		if(s(1)) ans += g[1].back() - g[1].front();
		if(s(2)) ans += g[2].back() - g[2].front();
		cout << ans;
		return 0;
	}


	if(s(1)) {
		ans += max(0, g[0].front() - g[1].front());
		ans += max(0, g[1].back() - g[0].back());
	}

	if(s(2)) {
		ans += max(0, g[0].front() - g[2].front());
		ans += max(0, g[2].back() - g[0].back());
	}


	int lastblue = 0, lastred = 0;

	for(int i = 1; i <= n; ++i){
		if(a[i].second == 1){
			if(lastred) red.update(lastred, a[i].first - a[lastred].first);
			red.Add(i);
			lastred = i;
		}
		if(a[i].second == 2){
			if(lastblue) blue.update(lastblue, a[i].first - a[lastblue].first);
			blue.Add(i);
			lastblue = i;
		}

		if(a[i].second == 0){
			if(lastblue) blue.update(lastblue, a[i].first - a[lastblue].first);
			if(lastred) red.update(lastred, a[i].first - a[lastred].first);
			red.Add(i);
			blue.Add(i);

			lastred = i;
			lastblue = i;
		}
	}

	for(int i = 1; i < pos.size(); ++i){
		int x = pos[i];
		int y = pos[i - 1];
		int d = a[x].first - a[y].first;

		int r = cnt[x][1] - cnt[y][1];
		int b = cnt[x][2] - cnt[y][2];

		if(r == 0 && b == 0) {
			ans += a[x].first - a[y].first;
			continue;
		}

		if(r == 0){
			ans += d + d - blue.ask(x, y, x);
			continue;
		}
		if(b == 0){
			ans += d + d - red.ask(x, y, x);
			continue;
		}

		ans += min(d + d, d + d + d - blue.ask(x, y, x) - red.ask(x, y, x));
		

	}

	cout << ans;

	return 0;
}