#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
int n;
int arr[N];
vector < int > v;
long long ans;
void solve(int l , int r , int ql , int qr){
	if(l > r){
		return;
	}
	if(ql == qr){
		for(int i = l ; i <= r ; ++i){
			ans += abs(v[ql] - arr[i]);
		}
		return;
	}
	int mid = ql + qr >> 1;
	int sum = 0;
	int bst = 0;
	int idx = l - 1;
	for(int i = l ; i <= r ; ++i){
		sum += (v[mid] < arr[i]) ? -1 : 1;
		if(sum > bst){
			bst = sum;
			idx = i;
		}
	}
	solve(l , idx , ql , mid);
	solve(idx + 1 , r , mid + 1 , qr);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		arr[i] -= i;
		v.emplace_back(arr[i]);
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	solve(1 , n , 0 , v.size() - 1);
	printf("%lld\n" , ans);
}