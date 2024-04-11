//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

LL n;

bool cango(LL x, LL y){
	return x * x + y * y <= n * n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n == 0){
		cout << 1 << endl;
		return 0;
	}
	if(n == 1){
		cout << 4 << endl;
		return 0;
	}
	int ptr = 1,
		ans = 1;
	for(int i = n - 1; i > 0; i--){
		bool x = false;
		while(cango(i, ptr))
			ptr++, ans++, x = true;
		if(!x) ans++;
	}
	cout << ans * 4 << '\n';
	return 0;
}