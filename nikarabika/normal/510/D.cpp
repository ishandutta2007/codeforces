//In the name of "God"
/*
   sar-e sobh
   man-e khol
   bazam didim lab-e pol
   migi balaE ya mikhI beri tah-e god
   migam inja mano khoda dare mibine
   miyad az roo dousham bar-e ghamo migire
   doone ashko az goone ham michineh
   miyad pisham ye goosheE mishine
   miboosam
   bem mige doosam dare
   doost dare khandehamo bebine
   dast-e ma ro migireh
   "Sadegh"
*/
#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 3e2 + 5;
int dp[maxn][1 << 9];
vector<int> v;
int l[maxn], c[maxn];
int n;

void factors(int x){
	v.clear();
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0)
			v.PB(i);
		while(x % i == 0)
			x /= i;
	}
	if(x > 1)
		v.PB(x);
}

int DP(int x, int pf){
	if(pf == 0)
		return 0;
	if(x == -1)
		return 1e9;
	if(dp[x][pf] != 0)
		return dp[x][pf];
	dp[x][pf] = DP(x - 1, pf);
	int temp = 0;
	for(int i = 0; i < v.size(); i++) 
		if(l[x] % v[i] == 0)
			temp = temp | (1 << i);
	dp[x][pf] = min(dp[x][pf], DP(x - 1, pf & temp) + c[x]);
	return dp[x][pf];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> l[i];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		memset(dp, 0, sizeof dp);
		factors(l[i]);
		ans = min(ans, DP(i - 1, (1 << int(v.size())) - 1) + c[i]);
	}
	cout << ((ans == 1e9) ? -1 : ans) << endl;
	return 0;
}