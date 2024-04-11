#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
const LL D = 1e9 + 7;
bool col[maxn];
vector<int> v[maxn];
vector<LL> lmul[maxn];
LL dp[maxn], pd[maxn];
int n;

void dfs(int x){
	if(v[x].size() == 0){
		if(col[x]) dp[x] = 1, pd[x] = 1;
		else dp[x] = 1, pd[x] = 0;
		return;
	}
	LL mul = 1, F = 0;
	lmul[x].resize(v[x].size());
	for(int i = 0; i < v[x].size(); i++){
		int y = v[x][i];
		dfs(y);
		lmul[x][i] = mul;
		mul = (mul * dp[y]) % D;
	}
	mul = 1;
	for(int i = v[x].size() - 1; i >= 0; i--){
		F = (F + ((((lmul[x][i] * mul) % D) * pd[v[x][i]]) % D)) % D;
		mul = (mul * dp[v[x][i]]) % D;
	}
	LL pidi = (lmul[x][v[x].size() - 1] * dp[v[x].back()]) % D;
	if(col[x]){
		dp[x] = pidi;
		pd[x] = pidi;
	}
	else{
		dp[x] = pidi + F;
		pd[x] = F;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
		v[x].PB(i);
	}
	bool xnxx = false;
	for(int i = 0; i < n; i++){
		cin >> col[i];
		xnxx = xnxx or col[i];
	}
	if(!xnxx){
		cout << 1 << endl;
		return 0;
	}
	dfs(0);
	cout << pd[0] << endl;
	return 0;
}