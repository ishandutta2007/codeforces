//In the name of "God"
//inam bara hame oonaE ke ba intori code zadan haal mikonan :D
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 85 - 69;
int n, a[maxn];
long long ans[maxn], Max[maxn];

void input(){
	string s;
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
		a[i] = s[i] - '0';
}

void DP(int x){
	if(Max[x] != -1)
		return;
	Max[x] = 0;
	ans[x] = 1;
	if(x == n)
		return;
	DP(x + 1);
	Max[x] = Max[x + 1];
	ans[x] = ans[x + 1];
	int sum = a[x] + a[x + 1];
	int p = x + 2;
	if(sum == 9){
		if(Max[x] == Max[p] + 1)
			ans[x] += ans[p];
		else if(Max[x] < Max[p] + 1)
			ans[x] = ans[p];
		Max[x] = max(Max[x], Max[p] + 1);
	}
}

void output(){
	cout << ans[0] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(Max, -1, sizeof Max);
	input();
	DP(0);
	output();
	return 0;
}