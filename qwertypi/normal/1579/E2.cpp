#include <bits/stdc++.h>

using namespace std;

struct BIT{
	int n;
	int bit[400003] = {0};
	void init(int n){
		this->n = n;
		fill(bit, bit + n + 1, 0);
	}
	void add(int p, int v){
		while(p <= n){
			bit[p] += v;
			p += p & -p;
		}
	}
	int qry(int p){
		int res = 0;
		while(p){
			res += bit[p];
			p -= p & -p;
		}
		return res;
	}
} bit;

int A[200001]; 
int sm[200001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	vector<int> v;
	for(int i = 0; i < n; i++) v.push_back({A[i]});
	sort(v.begin(), v.end());
	int k = unique(v.begin(), v.end()) - v.begin();
	v.resize(k);
	map<int, int> M; for(int i = 0; i < v.size(); i++) M[v[i]] = i + 1;
	for(int i = 0; i < n; i++) A[i] = M[A[i]];
	long long tinv = 0;
	bit.init(n);
	for(int i = 0; i < n; i++){
		tinv += min(i - bit.qry(A[i]), bit.qry(A[i] - 1));
		bit.add(A[i], 1);
	}
	cout << tinv << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}