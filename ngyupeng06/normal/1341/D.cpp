#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

int n, m, k;

string dig[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

string dp[2][2005];

string arr[2005];

pair<string, int> bruh[2005];

int thing[2005][10];

int diff(string a, int b){
	string x = dig[b];
	bool gd = true;
	int ans = 0;
	for (int i=0; i<7; i++){
		int y = x[i] - a[i];
		if (y<0){
			gd = false;
			break;
		}
		else ans += y;
	}
	if (gd) return ans;
	else return -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	dp[0][0] = "";
	for (int i=1; i<=k; i++){
		dp[0][i] = ".";
	}
	for (int i=0; i<n; i++){
		bruh[i] = mp(arr[i],i);
	}
	sort(bruh, bruh+n);
	for (int i=0; i<n; i++){
		if (i!=0 && bruh[i].first == bruh[i-1].first){
			for (int j=0; j<10; j++){
				thing[bruh[i].second][j] = thing[bruh[i-1].second][j];
			}
		}
		else{
			for (int j=0; j<10; j++){
				thing[bruh[i].second][j] = diff(arr[bruh[i].second], j);
			}
		}
	}
	for (int i=0; i<n; i++){
		int x = n-1-i;
		for (int j=0; j<=k; j++){
			bool gd = false;
			for (int l=9; l>=0; l--){
				int y = thing[x][l];
				if (!gd && y>=0 && y<=j && dp[i%2][j-y] != "."){
					char xx = l + '0';
					dp[(i+1)%2][j] = "";
					dp[(i+1)%2][j] += xx;
					dp[(i+1)%2][j] += dp[i%2][j-y];
					gd = true;
					break;
				}
			}
			if (!gd) dp[(i+1)%2][j] = ".";
		}
	}
	if (dp[n%2][k] != ".") cout << dp[n%2][k];
	else cout << "-1";
}