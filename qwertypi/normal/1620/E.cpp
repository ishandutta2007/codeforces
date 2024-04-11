#include <bits/stdc++.h>
#define N 500000
 
using namespace std;
 
int p[N];
int r[N];
vector<int> A[N + 1];
int ans[N];
 
void join(int x, int y){
	if(x == y) return;
	if(A[r[x]].size() < A[r[y]].size()){
		for(auto i : A[r[x]]) A[r[y]].push_back(i);
		A[r[x]].clear();
		p[r[x]] = r[y];
	}else{
		for(auto i : A[r[y]]) A[r[x]].push_back(i);
		A[r[y]].clear();
		p[r[y]] = r[x];
		swap(r[x], r[y]);
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	for(int i = 0; i <= N; i++){
		r[i] = i;
	}
	for(int i = 0; i < q; i++){
		int t, x, y;
		cin >> t;
		if(t == 1){
			cin >> x;
			A[r[x]].push_back(i);
		}else if(t == 2){
			cin >> x >> y;
			join(x, y);
		}
	}
	for(int i = 1; i <= N; i++){
		for(auto j : A[r[i]]){
			ans[j] = i;
		}
	}
	for(int i = 0; i < q; i++){
		if(ans[i]) cout << ans[i] << ' ';
	}
	cout << endl;
}