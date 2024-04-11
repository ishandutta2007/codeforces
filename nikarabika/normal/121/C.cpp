#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 20;
vector<int> num;
bool mark[maxn];
LL fact[maxn], a[maxn];
LL base, ans;
LL n, k;

bool islucky(LL x){
	while(x){
		if(x % 10 != 7 and x % 10 != 4)
			return false;
		x /= 10;
	}
	return true;
}

LL get_lucky(int pos = sz(num) - 1){
	if(pos == -1)
		return 0;
	if(num[pos] < 4)
		return 0;
	if(num[pos] == 4)
		return get_lucky(pos - 1);
	if(num[pos] < 7)
		return 1LL << pos;
	if(num[pos] == 7)
		return (1LL << pos) + get_lucky(pos - 1);
	return 2LL << pos;
}

void build(LL pos, LL cnt, LL dig){
	if(pos == dig)
		return;
	LL p = 0, rem = cnt / fact[dig - pos - 1];
	while(rem != -1){
		rem -= !mark[p];
		p++;
	}
	p--;
	a[pos] = p;
	mark[p] = true;
	build(pos + 1, cnt % fact[dig - pos - 1], dig);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	for(LL i = 1; i < 15; i++)
		fact[i] = fact[i - 1] * i;
	cin >> n >> k;
	if(n < 15 and k > fact[n]){
		cout << -1 << endl;
		return 0;
	}
	LL base = min(n, 14LL);
	build(0, k - 1, base);
	base = n - base;
	for(LL i = base + 1; i <= n; i++)
		ans += islucky(i) and islucky(a[i - base - 1] + base + 1);
	base++;
	while(base){
		num.PB(base % 10);
		base /= 10;
	}
	ans += get_lucky() + ((1LL << sz(num)) - 2);
	cout << ans << endl;
	return 0;
}