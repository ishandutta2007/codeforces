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

LL f(LL val){
	LL ret = 0;
	for(int i = 60; i > 0; i--)
		if((val >> i) & 1LL)
			if(!((((1LL << i) - 1) & val) & 1))
				ret ^= 1LL << i;
	val++;
	if((val / 2) & 1LL)
		ret ^= 1;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	LL ans = 0;
	cin >> n;
	while(n--){
		LL x, m;
		cin >> x >> m;
		ans ^= f(x - 1) ^ f(x + m - 1);
	}
	if(ans)
		cout << "tolik";
	else
		cout << "bolik";
	return 0;
}