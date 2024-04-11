#include <bits/stdc++.h>
#define double long double

using namespace std;

const int N = 100010;

int n, q;
double a[N];

double d[N << 3];
double b[N << 3];
double val[N << 3];

#define mid ((l + r) >> 1)

void remake(int x){
	val[x] = val[x + x] + val[x + x + 1];
}

void build(int x, int l, int r){
	d[x] = 1; b[x] = 0;
	if(l == r){
		val[x] = a[r];
		return;
	}
	build(x + x, l, mid);
	build(x + x + 1, mid + 1, r);
	val[x] = val[x + x] + val[x + x + 1];
}

void push(int x, int l, int r){
	if(d[x] != 1 || b[x] != 0){
		val[x] = d[x] * val[x] + b[x] * 1LL * (r - l + 1);

		b[x + x] *= d[x];
		d[x + x] *= d[x];
		b[x + x + 1] *= d[x];
		d[x + x + 1] *= d[x];
		
		b[x + x] += b[x];
		b[x + x + 1] += b[x]; 
	}
	d[x] = 1;
	b[x] = 0;
}

void dv(int x, int l, int r, int u, int v, double value){
	push(x, l, r);
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		d[x] *= value;
		push(x, l, r);
		return;
	}
	dv(x + x, l, mid, u, v, value);
	dv(x + x + 1, mid + 1, r, u, v, value);
	remake(x);
}

void add(int x, int l, int r, int u, int v, double value){
	push(x, l, r);
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		b[x] += value;
		return;
	}
	add(x + x, l, mid, u, v, value);
	add(x + x + 1, mid + 1, r, u, v, value);
	remake(x);
}

double query(int x, int l, int r, int u, int v){
	push(x, l, r);
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return val[x];
	double ans = query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
	remake(x);
	return ans;
}


int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	build(1, 1, n);

	cout << fixed << setprecision(7) << endl;

	while(q--){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 2){
			cout << query(1, 1, n, l, r) << '\n';
		}
		else{
			int u, v;
			cin >> u >> v;

			int m1 = r - l + 1,  m2 = v - u + 1;

			double one = query(1, 1, n, l, r);
			double two = query(1, 1, n, u, v);


			dv(1, 1, n, l, r, 1LL * (m1 - 1) * m2);
			dv(1, 1, n, u, v, 1LL * (m2 - 1) * m1);

			add(1, 1, n, l, r, two);
			add(1, 1, n, u, v, one);
			dv(1, 1, n, l, r, 1.0 / (double)(1LL * m1 * m2));
			dv(1, 1, n, u, v, 1.0 / (double)(1LL * m1 * m2));
		}
	}

	return 0;
}