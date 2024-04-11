#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
 
vpii sorted;
 
int cmp(pii A, pii B){
	return A.se > B.se;
}
 
int A[12][12];
 
void Swap(int k, int n){
	vector<int> C;
	for(int i=0;i<n;i++){
		C.emplace_back(A[i][k-1]);
	}
	rotate(C.begin(), C.begin()+1, C.end());
	for(int i=0;i<n;i++){
		A[i][k-1] = C[i];
	}
}
 
int f(int n, int k){
	if(k == 0){
		int res = 0;
		for(int i=0;i<n;i++){
			res += *max_element(A[i], A[i]+n);
		}
		return res;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, f(n, k-1));
		Swap(k, n);
	}
	return ans;
}
 
void Solve(){
	sorted.clear();
	int B[12][2000];
	set<int> used;
	vector<int> best;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int v;
			cin >> v;
			B[i][j] = v;
			sorted.emplace_back(pii{i*m+j, v});
		}
	}
	sort(sorted.begin(), sorted.end(), cmp);
	for(auto i:sorted){
		if(used.size() >= n){
			break;
		}
		used.insert(i.fi % m);
		best.emplace_back(i.fi);
	}
	vector<int> temp(used.begin(), used.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j] = temp.size() > j ? B[i][temp[j]] : 0;
		}
	}
	int ans = 0;
	cout << f(n, n) << endl; 
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}