#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = N * 150;

int n;

template < class Integer > 
class PersisdentSegementree{
	private :
		Integer value[N * 30];
		int cnt, L[N * 30], R[N * 30];
		
		Integer Merge(Integer x, Integer y){
			/// Insert Something here
			return x + y;
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

PersisdentSegementree < long long > Psmt;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int q;




	scanf("%d%d", &n, &q);

	Psmt.Initilize();
	Psmt.Build(1, 1, n);

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		Psmt.update(x, 1);
		Psmt.Add(i);
	}



	while(q--){
		int x, y, u, v;
		
		scanf("%d%d%d%d", &x, &y, &u, &v);

	//	cout << x << " " << y << endl;

		long long ans = 1LL * n * (n - 1) / 2;
		long long lef = Psmt.range(1, n, 1, y - 1);
		long long rig = Psmt.range(1, n, v + 1, n);
		long long up = Psmt.range(1, x - 1, 1, n);
		long long dwn = Psmt.range(u + 1, n, 1, n);

		//cout << lef << " " << rig << " " << up << " " << dwn << endl;


		ans -= 1LL * (lef * (lef - 1)) / 2;
		ans -= 1LL * (up * (up - 1)) / 2;
		ans -= 1LL * (dwn * (dwn - 1)) / 2;
		ans -= 1LL * (rig * (rig - 1)) / 2;
//		cout << ans << endl;

		lef = Psmt.range(1, x - 1, 1, y - 1);
		rig = Psmt.range(1, x - 1, v + 1, n);
		up = Psmt.range(u + 1, n, 1, y - 1);
		dwn = Psmt.range(u + 1, n, v + 1, n);

		//cout << lef << " " << rig << " " << up << " " << dwn << endl;


		ans += 1LL * (lef * (lef - 1)) / 2;
		ans += 1LL * (up * (up - 1)) / 2;
		ans += 1LL * (dwn * (dwn - 1)) / 2;
		ans += 1LL * (rig * (rig - 1)) / 2;

		printf("%lld\n", ans);

	}

	return 0;
}