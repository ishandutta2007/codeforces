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

const int SK = 72;
const int P = 20;
const ll MOD = (int)1e9 + 7;
int st[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
int ix[SK];
int odd[SK];
int even[SK];
int mask[SK];

bool is(int x){
	if(x == 1)
		return false;
	for(int y = 2;y * y <= x;y++)
		if(x % y == 0)
			return false;
	return true;
}

int divide(int x,int y){
	if(x % y != 0)
		return 0;
	else
		return divide(x/y,y) + 1;
}

void init(){
	for(int i = 0;i<P;i++)ix[st[i]] = i;
	for(int i = 0;i<SK;i++)even[i] = 1;
	for(int i = 1;i<SK;i++){
		if(!is(i))
			continue;
		for(int j = 1;j<SK;j++){
			if(divide(j,i) % 2 == 0)
				continue;
			mask[j] |= (1 << ix[i]);
		}
	}
}

ll dp[2][1 << P];

int main(){
	fastIO;
	init();
	int n;
	cin >> n;
	int x;
	int g;
	for(int j = 0;j<n;j++){
		cin >> x;
		g = (even[x] + odd[x]) % MOD;
		even[x] = g;
		odd[x] = g;
	}
	dp[0][0] = 1;
	int ix = 0;
	int nex = 1;
	for(int i = 0;i<=70;i++){
		for(int j = 0;j<(1 << P);j++){
			dp[nex][j ^ mask[i]] = (dp[nex][j ^ mask[i]] + ((1LL * dp[ix][j] * odd[i]) % MOD)) % MOD;
			dp[nex][j] = dp[nex][j] +  (dp[ix][j] * even[i] * 1LL) % MOD;
		}
		for(int j = 0;j<(1<<P);j++)
			dp[ix][j] = 0;
		ix ^= 1;
		nex ^= 1;
	}
	cout << (dp[1][0] - 1 /*remove the empty subset*/+ MOD )% MOD << "\n";
	return 0;
}