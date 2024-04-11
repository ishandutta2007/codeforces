#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
char l[N];
char r[N];
int pw10[N];
struct data{
	int ans;
	int lft;
	int rgt;
	int cnt;
	int sum;
	bool pos;
	data(bool _pos = 0){
		ans = 0;
		lft = 0;
		rgt = 0;
		sum = 0;
		cnt = _pos;
		pos = _pos;
	}
};
inline data combine(const data &a , const data &b){
	data res;
	res.lft = a.pos ? a.lft : b.lft;
	res.rgt = b.pos ? b.rgt : a.rgt;
	res.pos = a.pos | b.pos;
	res.cnt = a.cnt + b.cnt;
	res.cnt -= (res.cnt >= mod) * mod;
	res.sum = a.sum + b.sum;
	res.sum -= (res.sum >= mod) * mod;
	res.ans = (a.ans + b.ans + 1LL * a.rgt * b.lft) % mod;
	return res;
}
bool calc[N][2][2];
data dp[N][2][2];
data solve(int pos , bool prea , bool preb){
	if(pos > n){
		return data(1);
	}
	if(calc[pos][prea][preb]){
		return dp[pos][prea][preb];
	}
	int diga = l[pos] - '0';
	int digb = r[pos] - '0';
	data a , b;
	if((prea || (4 >= diga)) && (preb || (4 <= digb))){
		a = solve(pos + 1 , prea | (4 > diga) , preb | (4 < digb));
		long long add = 4LL * pw10[n - pos];
		add %= mod;
		if(a.pos){
			long long sq = (add * add) % mod;
			a.ans = (a.ans + sq * (a.cnt - 1LL)) % mod;
			a.ans = (a.ans + (2LL * a.sum - a.lft - a.rgt) * add) % mod;
			a.ans += (a.ans < 0) * mod;
			a.sum = (a.sum + add * a.cnt) % mod;
			a.lft = (a.lft + add) % mod;
			a.rgt = (a.rgt + add) % mod;
		}
	}
	if((prea || (7 >= diga)) && (preb || (7 <= digb))){
		b = solve(pos + 1 , prea | (7 > diga) , preb | (7 < digb));
		long long add = 7LL * pw10[n - pos];
		add %= mod;
		if(b.pos){
			long long sq = (add * add) % mod;
			b.ans = (b.ans + sq * (b.cnt - 1LL)) % mod;
			b.ans = (b.ans + (2LL * b.sum - b.lft - b.rgt) * add) % mod;
			b.ans += (b.ans < 0) * mod;
			b.sum = (b.sum + add * b.cnt) % mod;
			b.lft = (b.lft + add) % mod;
			b.rgt = (b.rgt + add) % mod;
		}
	}
	calc[pos][prea][preb] = 1;
	return dp[pos][prea][preb] = combine(a , b);
}
int main(){
	scanf("%s" , l + 1);
	scanf("%s" , r + 1);
	n = strlen(l + 1);
	pw10[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		pw10[i] = (pw10[i - 1] * 10LL) % mod;
	}
	printf("%d\n" , solve(1 , 0 , 0).ans);
}