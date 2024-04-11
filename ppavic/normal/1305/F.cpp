#include <bits/stdc++.h>
 
#define ll long long
#define fi first
#define se second
 
using namespace std;
 
const int maxn = 2e5 + 10;
 
int n;
ll ans;
ll arr[maxn];
vector <ll> v;
 
void test(ll x){
	if(!x) return;
	
	//cout << x << endl;
	
	while(x % 2 == 0) x /= 2;
	
	for(ll j = 3; j * j <= x; j++){
		if(x % j == 0){
			ll cnt = 0;
			
			for(int i = 0; i < n; i++){
				if(arr[i] < j) cnt += j - arr[i];
				else cnt += min(arr[i] % j, j - arr[i] % j);
				
				if(cnt >= ans) break;
			}
			
			ans = min(ans, cnt);
		}
		
		while(x % j == 0) x /= j;
	}
	
	if(x != 1){
		ll cnt = 0;
		
		for(int i = 0; i < n; i++){
			if(arr[i] < x) cnt += x - arr[i];
			else cnt += min(arr[i] % x, x - arr[i] % x);
			
			if(cnt >= ans) break;
		}
		
		//cout << x << ' ' << cnt << endl;
		
		ans = min(ans, cnt);
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		ans += (arr[i] % 2);
		v.push_back(arr[i]);
	}
	
	//cout << ans << endl;
	
	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
	
	int m = v.size();
	
	for(int i = 0; i < 50; i++){
		int x = rand() * rand() % m;
				
		for(int d = -1; d <= 1; d++){
			test(v[x] + d);
		}
	}
	
	cout << ans;
	
	return 0;
}