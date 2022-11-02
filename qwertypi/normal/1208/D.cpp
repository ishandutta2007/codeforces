#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
 
ll tr[200000][20];
int Parent[200000];
 
int Root(int x){
	while(Parent[x] != x){
		Parent[x] = Parent[Parent[x]];
		x = Parent[x];
	}
	return x;
}
 
void Union(int x, int y){
	if(x > y) swap(x, y);
	int Root_x = Root(x), Root_y = Root(y);
	Parent[Root_x] = Root_y;
}
 
void Change(int x, int n){
	int k = ceil(log2(n+1));
	for(int i=0;i<=k;i++){
		tr[(x >> i) << i][i] -= x + 1;
	}
}
 
ll Sum(int n){
	n++;
	int k = ceil(log2(n+1));
	ll res = 0;
	for(int i=0;i<k;i++){
		if((n >> i) % 2 == 1){
			res += tr[((n >> i) - 1) << i][i];
		}
	}
	res -= tr[n-1][0];
	return res;
}
 
int bin_search(int n, ll val){
	int upper = n - 1;
	int lower = 0;
	while(lower != upper){
		int mid = (lower + upper) / 2;
		if(Sum(mid) >= val){
			upper = mid;
		}else{
			lower = mid + 1; 
		}
	}
	return lower;
}
 
ll A[200000];
int ans[200000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		tr[i][0] = i + 1;
		Parent[i] = i;
	}
	int k = ceil(log2(n+1));
	for(int i=1;i<k;i++){
		for(int j = 0; j < n - (1 << i) + 1; j += (1 << i)){
			tr[j][i] = tr[j][i-1] + tr[j + (1 << (i-1))][i-1];
		}
	}
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=n-1;i>=0;i--){
		int v = Root(bin_search(n, A[i]));
		Change(v, n);
		if(v != n-1)
			Union(v, v + 1);
		ans[i] = v + 1;
	}
	for(int i=0;i<n;i++){
		cout << ans[i] << ' ';
	}
}