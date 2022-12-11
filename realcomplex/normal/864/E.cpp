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

struct ITEM{
	int burn_off;
	int fixing;
	int value;
	int index;
};

const int N = 123;
const int D = 2000 + 123;

bool comp_Items(ITEM a,ITEM b){
	if(a.burn_off < b.burn_off)
		return true;
	else if(a.burn_off > b.burn_off)
		return false;
	if(a.fixing < b.fixing)
		return true;
	else if(a.fixing > b.fixing)
		return false;
	if(a.value > b.value)
		return true;
	else
		return false;
	return true;
}

int dp[N][D]; // maximum value by taking [1..i] items in j seconds
int state_from[N][D];

void init(){
	for(int i = 0;i<N;i++)
		for(int j =0;j<D;j++)
			state_from[i][j] = -1; 
}

int main(){
	fastIO;
	init();
	int n;
	cin >> n;
	ITEM st[n];
	for(int i = 0;i<n;i++){
		cin >> st[i].fixing>> st[i].burn_off >> st[i].value;
		st[i].index = i;
	}
	sort(st,st+n,comp_Items);
	int p = 1;
	int ans = 0;
	int r = 0,c = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<D;j++)
			state_from[p][j] = j,dp[p][j] = dp[p-1][j]; 
		for(int j = st[i].fixing;j<st[i].burn_off;j++){
			if(dp[p-1][j-st[i].fixing] + st[i].value > dp[p][j]){
				dp[p][j] = dp[p-1][j-st[i].fixing] + st[i].value;
				state_from[p][j] = j-st[i].fixing;
			}
			if(dp[p][j] > ans){
				ans = dp[p][j];
				r = p;
				c = j;
			}
		}
		++p;
	}
	cout << ans << "\n";
	vector<int>ix;
	while(r > 0){
		if(state_from[r][c] != c){
			ix.push_back(st[r-1].index);
		}
		c = state_from[r][c];
		--r;
	}
	reverse(ix.begin(),ix.end());
	cout << ix.size() << "\n";
	for(auto x : ix)
		cout << x+1 << " ";
	cout << "\n";
	return 0;
}