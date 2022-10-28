#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int ans;
int main(){
	cin >> n;
	n *= 2;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	sort(arr + 1 , arr + 1 + n);
	ans = 1e9;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = i + 1 ; j <= n ; ++j){
			vector < int > v;
			v.clear();
			for(int k = 1 ; k <= n ; ++k){
				if(k == i || k == j){
					continue;
				}
				v.emplace_back(arr[k]);
			}
			int tot = 0;
			for(int i = 1 ; i < v.size() ; i += 2){
				tot += v[i] - v[i - 1];
			}
			ans = min(ans , tot);
		}
	}
	printf("%d\n" , ans);
}