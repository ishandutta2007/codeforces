#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

struct node{
	int a, b, c;
}it[N * 4];

string s;

node combine(node u, node v){
	int fix = min(u.b, v.c);
	node result;
	result.a = v.a + u.a + fix;
	result.b = u.b + v.b - fix;
	result.c = u.c + v.c - fix;
	return result; 
}

int n, m;

void build(int i, int l, int r){	
	

	if(l == r){
		if(s[l] == '('){
		 	it[i].b = 1;
		}
		else{
			it[i].c = 1;
		}
		return;
	}	

	int mid = (l + r) >> 1;
	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);
	it[i] = combine(it[i * 2], it[i * 2 + 1]);
}

int d, c;

node query(int i, int l, int r){
	if(d > r || l > c) return {0, 0, 0};
	if(l >= d && r <= c) return it[i];
	int mid = (l + r) >> 1;
	return combine(query(i * 2, l, mid), query(i * 2 + 1, mid + 1, r));
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("sol.inp", "r", stdin);
		freopen("sol.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin >> s >> m;

	n = s.size();
	s = " " + s;

	build(1, 1, n);

	for(int i = 1; i <= m; ++i){
		cin >> d >> c;
		cout << query(1, 1, n).a * 2<< "\n";			
	}

	return 0;
}