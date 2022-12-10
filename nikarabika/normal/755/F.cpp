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
const int maxsq = 100;
int cnt[maxn];
int p[maxn],
	n, k;
bool mark[maxn];
bitset<maxn / 2> bs;
bool tmp[maxn];

int getmin(void){
	//for(int i = n; i >= 2; i--){
	int rem = min(k, n - k);
	bs[0] = 1;
	for(int i = 2; i <= n; ++i)if(cnt[i]){
		if(i <= maxsq){
			for(int r = 0; r < i; ++r){
				int su = 0, ptr = 0;
				for(int j = r; j <= k; j += i){
					if(bs[j]) su++;
					tmp[ptr++] = bs[j];
					bs[j] = bs[j] or su;
					if(j - cnt[i] * i >= 0 and tmp[(j - r) / i - cnt[i]]) su--;
				}
			}
		}
		else
			for(int j = 0; j < cnt[i]; ++j)
				bs |= bs << i;
		if(bs[rem]) return k;
	}
	return k + 1;
}

int getmax(void){
	int ret = 0,
		rem = k;
	for(int i = 2; i <= n; i += 2){
		for(int j = 0; j < cnt[i] and rem; j++){
			if(i / 2 <= rem){
				ret += i;
				rem -= i / 2;
			}
			else{
				ret += 2 * rem;
				rem = 0;
			}
		}
	}
	if(!rem) return ret;
	int c = 0;
	for(int i = 1; i <= n; i += 2){
		for(int j = 0; j < cnt[i] and rem; ++j){
			if(i / 2 <= rem){
				ret += i - 1;
				c++;
				rem -= i / 2;
			}
			else{
				ret += 2 * rem;
				rem = 0;
			}
		}
	}
	return ret + min(c, rem);
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", p + i), --p[i];
	for(int i = 0; i < n; ++i) if(!mark[i]){
		int u = i;
		int len = 0;
		while(!mark[u]){
			mark[u] = true;
			len++;
			u = p[u];
		}
		++cnt[len];
	}
	cout << getmin() << ' ';
	cout << getmax() << '\n';
	return 0;
}