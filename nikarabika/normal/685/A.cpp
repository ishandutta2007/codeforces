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

LL ans = 0;
int num[100];
bool mark[7];
int n, m, fn, fm;

int f(int x){
	x--;
	int ret = 0;
	while(x)
		ret++, x/=7;
	return max(1, ret);
}

void build(int pos=0){
	if(pos == fm + fn){
		LL num1 = 0,
		   num2 = 0;
		for(int i = fn; i < fn + fm; i++)
			num2 = num2 * 7 + num[i];
		for(int i = 0; i < fn; i++)
			num1 = num1 * 7 + num[i];
		ans += (num1 < n and num2 < m);
		return;
	}
	for(int i = 0; i < 7; i++)
		if(!mark[i]){
			mark[i] = true;
			num[pos] = i;
			build(pos + 1);
			mark[i] = false;
		}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	fm = f(m), fn = f(n);
	if(fm + fn > 7){
		cout << 0 << endl;
		return 0;
	}
	build();
	cout << ans << endl;
	return 0;
}