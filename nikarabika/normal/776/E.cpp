//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 1e6 + 10;
const LL Mod = 1e9 + 7;
vector<LL> prim;
bool isp[maxn];

LL phi(LL x){
	LL ret = x;
	for(LL div : prim){
		if(div > ret) break;
		if(x % div == 0) ret -= ret / div;
		while(x % div == 0) x /= div;
	}
	if(x != 1) ret -= ret / x;
	return ret;
}

LL func(LL x){
	if(x == 1) return 0;
	return func(phi(x)) + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(isp, true, sizeof isp);
	isp[0] = isp[1] = false;
	for(int i = 0; i < maxn; i++)
		if(isp[i])
		{
			for(int j = i + i; j < maxn; j += i)
				isp[j] = false;
			prim.PB(i);
		}
	LL n, k;
	cin >> n >> k;
	if(k % 2 == 0) k--;
	while(n != 1 and k > 0){
		n = phi(n);
		k -= 2;
	}
	cout << (n % Mod) << '\n';
	return 0;
}