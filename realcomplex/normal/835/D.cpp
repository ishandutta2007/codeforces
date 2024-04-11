#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())

const int MAX_SIZE = 5005;
int dp[MAX_SIZE][MAX_SIZE];
int cnt[MAX_SIZE];

int main(){
	fastIO;
	string s;
	cin >> s;
	int n=  s.size();
	for(int i = 0;i<n;i++){
		dp[i][i] = 1;
		if(i < n-1){
			if(s[i] == s[i+1])
				dp[i][i+1] = 2;
		}
	}
	int mid;
	for(int i = 2;i<n;i++){
		for(int j = i-2;j>=0;j--){
			if(s[i] != s[j])
				continue;
			if(dp[j+1][i-1] == 0)
				continue;
			//if((j - i) % 2 == 0){
				mid = (i+j+1)/2;
				mid--;
				dp[j][i] = dp[j][mid] + 1;
			//}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cnt[dp[i][j]]++;
		}
	}
	for(int i = n;i>=0;i--)
		cnt[i] +=cnt[i+1];
	for(int i = 1;i<=n;i++)
		cout << cnt[i] << " ";
	return 0;
}