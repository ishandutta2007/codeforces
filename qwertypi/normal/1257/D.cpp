#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int st[200000][20];
	
vector<pair<int, int>> heros;
vector<int> A;
vector<int> prec; 
 
int n, m;
 
int getMax(int x){
	int upper = m - 1;
	int lower = 0;
	while(upper != lower){
		int mid = (upper + lower + 1) / 2;
		if(heros[mid].first >= x){
			lower = mid;
		}else{
			upper = mid - 1;
		}
	}
	return prec[lower + 1];
}
 
int getValue(int l, int r){
	int k = floor(log2(r - l + 1) + 1e-9);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}
 
int bin_search(int x){
	int upper = n - 1;
	int lower = x;
	while(upper != lower){
		int mid = (upper + lower + 1) / 2;
		if(getMax(getValue(x, mid)) >= mid - x + 1){
			lower = mid;
		}else{
			upper = mid - 1;
		}
	}
	return lower + 1;
}
 
void sub(){
	cin >> n;
	int _max = 0;
	A.clear();
	A.resize(n);
	for(int i = 0; i < n; i++){
		cin >> A[i];
		st[i][0] = A[i];
		_max = max(_max, A[i]);
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= (n - (1 << j)); i++){
			st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j-1]);
		}
	}
	cin >> m;
	heros.clear();
	heros.resize(m + 1);
	for(int i = 0; i < m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		heros[i] = {v1, v2};
	}
	sort(heros.begin(), heros.begin() + m, [](pair<int, int> A, pair<int, int> B){
		return A.first > B.first || A.first == B.first && A.second > B.second;
	});
	if(heros[0].first < _max){
		cout << -1 << endl;
		return;
	}
	prec.clear();
	prec.resize(m + 1);
	prec[0] = 0;
	for(int i = 1; i <= m; i++){
		prec[i] = max(prec[i-1], heros[i-1].second);
	}
	int curPos = 0;
	int ans = 0;
	while(curPos != n){
		curPos = bin_search(curPos);
		ans++;
	}
	cout << ans << endl;
}
 
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}