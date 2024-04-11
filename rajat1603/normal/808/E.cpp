#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
pair < int , int > arr[N];
vector < long long > v[4];
long long ans;
long long solve12(int m){
	if(m == 0){
		return 0;
	}
	long long res = v[1][m - 1];
	for(int i = 1 ; i + i <= m ; ++i){
		res = max(res , ((m > i * 2) ? v[1][m - 2 * i - 1] : 0) + v[2][i - 1]);
	}
	return res;
}
long long solve(int val){
	if(val){
		return solve12(m - val * 3) + v[3][val - 1];
	}
	else{
		return solve12(m - val * 3);
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &arr[i].second , &arr[i].first);
	}
	sort(arr + 1 , arr + 1 + n);
	reverse(arr + 1 , arr + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		v[arr[i].second].push_back(arr[i].first);
	}
	for(int i = 1 ; i <= 3 ; ++i){
		for(int j = 0 ; j <= m ; ++j){
			v[i].emplace_back(0);
		}
	}
	for(int i = 1 ; i <= 3 ; ++i){
		for(int j = 1 ; j < v[i].size() ; ++j){
			v[i][j] += v[i][j - 1];
		}
	}
	int l = 0;
	int r = m / 3;
	ans = 0;
	while(r - l > 4){
		int mid1 = (l + l + r) / 3;
		int mid2 = (l + r + r) / 3;
		long long val1 = solve(mid1);
		long long val2 = solve(mid2);
		ans = max(ans , max(val1 , val2));
		if(val1 < val2){
			l = mid1;
		}
		else{
			r = mid2;
		}
	}
	for(int i = l ; i <= r ; ++i){
		ans = max(ans , solve(i));
	}
	printf("%lld\n" , ans);
}