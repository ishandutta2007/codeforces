#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL maxn = 1e6 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7;
LL n, k;
bool mark[maxn];
LL h[maxn], cnt[maxn], ans[maxn];

void dfs(LL v){
	mark[v] = true;
	LL u = (v * k) % n;
	if(!mark[u]){
		h[u] = h[v] + 1;
		dfs(u);
	}
	else
		cnt[h[v] + 1]++;
	return;
}

LL Pow(LL x, LL y){
	LL ret = 1;
	for(LL i = 0; i < y; i++)
		ret = (ret * x) % Mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if(k == 0){
		cout << Pow(n, n - 1) << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i);
	for(LL i = 1; i <= n; i++){
		for(LL j = i; j <= n; j += i)
			ans[j] = (ans[j] + ((cnt[i] * i) % Mod)) % Mod;
	}
	LL ret = 1;
	for(LL i = 1; i <= n; i++)
		ret = (ret * Pow(ans[i], cnt[i])) % Mod;
	cout << ret << endl;
	return 0;
}