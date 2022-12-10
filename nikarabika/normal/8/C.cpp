#include <bits/stdc++.h>
using namespace std;
#define L first
#define R second
#define xs XS
#define ys YS
#define PB push_back
#define MP make_pair
typedef pair<int , int> pii;

const int M = 24;
int dp[(1 << M) + 5] , n , xs , ys;
pii p[M] , par[(1<<M) + 5];

int fbi(int mask)
{
	for(int i = 0; i < n; i++)
		if((1 << i) & mask)
			return i;
	return -1;
}
int gti(int i , int j)
{
	int ret = (xs-p[i].L)*(xs-p[i].L)+(ys-p[i].R)*(ys-p[i].R)+(p[i].L-p[j].L)*(p[i].L-p[j].L)+(p[i].R-p[j].R)*(p[i].R-p[j].R)+(xs-p[j].L)*(xs-p[j].L)+(ys-p[j].R)*(ys-p[j].R);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> xs >> ys >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i].L >> p[i].R;
	memset(dp , 63 , sizeof dp);
	dp[0] = 0;
	for(int mask = 1; mask < (1 << n); mask++){
		int fi = fbi(mask);
		for(int j = 0; j < n; j++)
			if(((1 << j) & mask) && (dp[mask - (1<<j) - (fi == j ? 0:(1<<fi))] + gti(fi , j)) < dp[mask])
				dp[mask] = dp[mask - (1<<j) - (fi == j ? 0:(1<<fi))] + gti(fi , j) , par[mask] = MP(fi+1 , j+1);
	}
	cout << dp[(1<<n) - 1] << endl;
	int now = (1<<n) - 1;
	vector <int> ans;
	while(now > 0){
		int k = now;
		if(par[now].L == par[now].R)
			ans.PB(par[now].L) , now -= (1<<(par[now].L-1));
		else
			ans.PB(par[now].L) , ans.PB(par[now].R) , now -= (1<<(par[now].L-1)) , now -= (1<<(par[k].R-1));
		ans.PB(0);
	}
	while(!ans.empty()){
		cout << ans.back() << " ";
		ans.pop_back();
	}
	cout << 0 << endl;
	return 0;
}