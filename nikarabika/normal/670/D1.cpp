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

const int maxn = 1e5 + 85 - 69;
LL a[maxn],
   b[maxn],
   n, k, suma, sumb;

bool can_bake(LL x){
	LL tmp = k;
	for(int i = 0; i < n; i++){
		LL need = a[i] * x;
		if(need <= b[i])
			continue;
		if(need - b[i] > tmp)
			return false;
		tmp -= need - b[i];
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i], suma += a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i], sumb += b[i];
	LL lo = 0,
	   hi = (sumb + k) / suma + 1;
	while(hi - lo > 1){
		LL mid = (lo + hi) >> 1;
		if(can_bake(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
	return 0;
}