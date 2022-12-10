//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())
#define islucky(x) ((int)(x == 4 or x == 7))

const LL Mod = 1000LL * 1000 * 1000 + 7;
LL dp[15][15][15], pd[15][15][15], cnt[15];
LL ans;
vector<int> num;

void input(void){
	LL inp;
	cin >> inp;
	while(inp)
		num.PB(inp % 10), inp /= 10;
	return;
}

void build(int pos = sz(num), int fcnt = 0){
	if(pos == 0){
		cnt[fcnt]++;
		return;
	}
	for(int j = 0; j < num[pos - 1]; j++)
		for(int k = 0; k <= pos; k++)
			cnt[k + fcnt] += dp[pos][j][k];
	build(pos - 1, fcnt + islucky(num[pos - 1]));
	return;
}

LL C(LL n, LL r){
	if(r > n)
		return 0;
	LL a[r], ret = 1, makh = 1;
	for(LL i = 1; i <= r; i++){
		a[i - 1] = n - i + 1;
		makh *= i;
	}
	for(LL i = 0; i < r; i++){
		LL g = __gcd(a[i], makh);
		makh /= g;
		a[i] /= g;
		ret = (ret * a[i]) % Mod;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	for(int j = 0; j < 10; j++)
		dp[1][j][islucky(j)] = 1;
	for(int i = 2; i <= 10; i++)
		for(int j = 0; j < 10; j++)
			for(int k = islucky(j); k <= i; k++)
				for(int jj = 0; jj < 10; jj++)
					dp[i][j][k] += dp[i - 1][jj][k - islucky(j)];
	cnt[0]--;
	build();
	for(int j = 0; j <= 10; j++)
		for(int k = 0; k <= 10; k++)
			pd[0][j][k] = 1;
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j <= 10; j++){
			pd[i][j][0] = C(cnt[0], i);
			for(int k = 1; k <= 10; k++){
				LL &cur = pd[i][j][k];
				for(int ii = 0; ii <= i and j - ii * k >= 0; ii++)
					cur = (cur + ((C(cnt[k], ii) * pd[i - ii][j - ii * k][k - 1]) % Mod)) % Mod;
			}
		}
	}
	for(int i = 1; i <= 10; i++)
		ans = (ans + ((cnt[i] * pd[6][i - 1][10]) % Mod)) % Mod;
	cout << (ans * 720LL) % Mod << endl;
	return 0;
}