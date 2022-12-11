#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string revert(string op){
	if(op == "<")
		return ">";
	else if(op == ">")
		return "<";
	else if(op == ">=")
		return "<=";
	else if(op == "<=")
		return ">=";
	else
		return "=";
}

const int N = 35;
const int MX = N * 2;

vector<pair<string, int>> T[MX];

int n;

bool compare(int n1, string op, int n2){
	if(op == "=")
		return n1 == n2;
	else if(op == "<")
		return n1 < n2;
	else if(op == ">")
		return n1 > n2;
	else if(op == "<=")
		return n1 <= n2;
	else if(op == ">=")	
		return n1 >= n2;
}

bool check(int cl, int cr, int n1, int n2){
	int arr[n * 2];
	for(int i = 0 ; i < n * 2; i ++ ){
		if(i == n1 || i == n2)
			arr[i] = 1;
		else if(cl <= i && cr >= i)
			arr[i] = 2;
		else
			arr[i] = 0;
	}
	for(auto x : T[n1])
		if(!compare(arr[n1], x.fi, arr[x.se]))
			return false;
	for(auto x : T[n2])
		if(!compare(arr[n2], x.fi, arr[x.se]))
			return false;
	return true;
}

ll dp[N + 1][MX][MX];

int main(){
	fastIO;
	int k;
	cin >> n >> k;
	int m = n * 2;
	int xi, yi;
	string op;
	for(int i = 0; i < k ; i ++ ){
		cin >> xi >> op >> yi;
		-- xi;
		-- yi;
		T[xi].push_back(mp(op, yi));
		T[yi].push_back(mp(revert(op), xi));
	}
	dp[0][0][m - 1] = 1;
	ll ans = 0;
	int siz = m;

	for(int i = 1; i <= n; i ++ ){
		for(int l = 0; l < m; l ++ ){
			for(int r = l;r < m ;r ++ ){
				if(i == n && r - l + 1 == 2){
					if(check(l, r, l, r))
						ans += dp[i - 1][l][r];
				}
				else if(r - l + 1 == siz){
					if(check(l, r, l, l + 1))	
						dp[i][l + 2][r] += dp[i - 1][l][r];
					if(check(l, r, r - 1, r)){
						dp[i][l][r - 2] += dp[i - 1][l][r];
					}
					if(check(l, r, l, r))
						dp[i][l + 1][r - 1] += dp[i - 1][l][r];
				}
			}
		}
		
		siz -= 2;
	}
	cout << ans << "\n";
	return 0;
}