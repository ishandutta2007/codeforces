#include <bits/stdc++.h>

#define N (1 << 17)
using namespace std;
/* This is the implementation of segment tree */

int A[N];
int t[4 * N];

// point update, range query

// TO_FIND: what is the necessary property of the function combine?
// TODO: modify function update, combine

int n;

template<class T>
T combine(T x, T y, bool st){
	if(st){
		return x | y;
	}else{
		return x ^ y;
	}
}

void build(int l = 0, int r = (1 << n) - 1, int v = 0, bool state = n % 2){
	if(l == r){
		t[v] = A[l];
		return;
	}
	int m = (l + r) / 2;
	build(l, m, v * 2 + 1, state ^ 1);
	build(m + 1, r, v * 2 + 2, state ^ 1);
	t[v] = combine(t[v * 2 + 1], t[v * 2 + 2], state);
}

void update(int p, int x, int tl = 0, int tr = (1 << n) - 1, int v = 0, bool state = n % 2){
	if(tl == tr){
		t[v] = x;
		return;
	}
	int tm = (tl + tr) / 2;
	if(p <= tm){
		update(p, x, tl, tm, v * 2 + 1, state ^ 1);
	}else{
		update(p, x, tm + 1, tr, v * 2 + 2, state ^ 1);
	}
	t[v] = combine(t[v * 2 + 1], t[v * 2 + 2], state);
}

/*
template<class T>
T query(int l, int r, int tl = 0, int tr = n - 1, int v = 0){
	if(l > r){
		return 0;
	}
	if(l == tl && r == tr){
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return combine(query(l, min(tm, r), tl, tm, v * 2 + 1),
				   query(max(tm + 1, l), r, tm + 1, tr, v * 2 + 2), 0);  
}*/

int main(){
	cin >> n;
	int m;
	cin >> m;
	for(int i = 0; i < (1 << n); i++){
		cin >> A[i];
	}
	build();
	for(int i = 0; i < m; i++){
		int p, x;
		cin >> p >> x;
		p--;
		update(p, x);
		cout << t[0] << endl;
	}
}