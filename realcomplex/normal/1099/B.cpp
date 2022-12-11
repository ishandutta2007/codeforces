#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	int n;
	cin >> n;
	int ans = (int)2e9 + 9;
	int a, b;
	for(int i = 1; i <= (int)1e5; i ++ ){
		a = i;
		b = (n + i - 1)/i;
		ans = min(ans, a + b);
	}
	cout << ans;
	return 0;
}