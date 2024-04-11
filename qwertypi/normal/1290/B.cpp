#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int, int>> A;

vector<vector<char>> t(800000);

template<class T>
T combine(T x, T y){
	T res;
	set_union(x.begin(), x.end(), y.begin(), y.end(), back_inserter(res));
	return res;
}

int n;
string s;
void build(int l = 0, int r = n - 1, int v = 0){
	if(l == r){
		t[v] = {s[l]};
		return;
	}
	int m = (l + r) / 2;
	build(l, m, v * 2 + 1);
	build(m + 1, r, v * 2 + 2);
	t[v] = combine(t[v * 2 + 1], t[v * 2 + 2]);
}

template<class T>
T query(int l, int r, int tl = 0, int tr = n - 1, int v = 0){
	if(l > r){
		return {};
	}
	if(l == tl && r == tr){
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return combine(query<T>(l, min(tm, r), tl, tm, v * 2 + 1),
				   query<T>(max(tm + 1, l), r, tm + 1, tr, v * 2 + 2));  
}

int main(){
	cin >> s;
	n = s.size(); 
	build();
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		if(l == r){
			cout << "Yes" << endl;
			continue;
		}
		if(s[l] != s[r]){
			cout << "Yes" << endl;
			continue;
		}else{
			if(query<vector<char>>(l, r).size() >= 3){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}
	}
}