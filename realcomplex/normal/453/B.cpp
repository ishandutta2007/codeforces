#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 102;
const int MX = 61;

vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59};
const int BITS = 17;
const int SZ = 1 << BITS;

int mask[MX];
int dp[N][SZ];
int pv[N][SZ];

int calc_mask(int x){
	int ret = 0;
	for(int i = 0 ; i < pr.size() ; i ++ ){
		if(x % pr[i] == 0)
			ret |= (1 << i);
	}
	return ret;
}

void init(){
	for(int i = 1 ; i < MX; i ++ )
		mask[i] = calc_mask(i);
}

int absolute(int x){
	return max(x, -x);
}

int a[N];
int main(){
	fastIO;
	init();
	int n;
	cin >> n;
	int a[n];
	for(int i = 1 ; i <= n; i ++ ){
		cin >> a[i];
	}
	for(int i = 0 ; i < N; i ++ ){
		for(int j = 0 ; j < (1 << BITS) ;j ++ ){
			dp[i][j] = (int)1e7 + 9;
			pv[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	int pmask;
	int ldp;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 0 ; j < (1 << BITS) ; j ++ ){
			for(int nx = 1; nx < MX;  nx ++ ){
				if((j & mask[nx]) == mask[nx]){
					pmask = j ^ mask[nx];
					ldp = dp[i - 1][pmask] + absolute(a[i] - nx);
					if(dp[i][j] > ldp){
						pv[i][j] = nx;
						dp[i][j] = ldp;
					}
				}
			}
		}
	}
	int idx = -1;
	for(int j = 0 ; j < (1 << BITS); j ++ ){
		if(idx == -1 || dp[n][j] < dp[n][idx]){
			idx = j;
		}
	}
	vector<int> ret;
	for(int j = n; j >= 1; j -- ){
		ret.push_back(pv[j][idx]);
		idx ^= mask[pv[j][idx]];
	}
	reverse(ret.begin(), ret.end());
	for(auto x : ret)
		cout << x << " ";
	return 0;
}