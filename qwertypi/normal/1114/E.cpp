
#include <bits/stdc++.h>
 
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	int n;
	cin >> n;
	int l = 0, r = 1e9;
	while(l != r){
		int m = (l + r) >> 1;
		cout << "> " << m << endl;
		int v; cin >> v;
		if(v == 1){
			l = m + 1;
		}else{
			r = m;
		}
	}
	int gg = l;
	set<int> S;
	vector<int> vals;
	for(int i = 0; i < min(n, 30); i++){
		int v;
		do{
			v = 1 + rng() % n;	
		}while(S.find(v) != S.end());
		S.insert(v);
		cout << "? " << v << endl;
		int ret; cin >> ret;
		vals.push_back(gg - ret);
	}
	int g = 0;
	for(int i = 0; i < (int) vals.size(); i++){
		for(int j = i + 1; j < (int) vals.size(); j++){
			g = __gcd(g, vals[i] - vals[j]);
		}
	}
	g = abs(g);
	int a1 = gg - g * (n - 1), a2 = g;
	cout << "! " << a1 << ' ' << a2 << endl; 
}