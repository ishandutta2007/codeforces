#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 5020
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9) + 7;

char arr[MAX][MAX];
int   dp[MAX][MAX];
bool seen[MAX][MAX];

void deal(){
	fori(MAX)
		forj(MAX){
			dp[i][j] = 0;
			arr[i][j] = 'z';
		}
	int n,k;
	cin>>n>>k;
	fori(n)
		forj(n)
			cin>>arr[i+1][j+1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			dp[i][j]=  dp[i-1][j] + (arr[i][j] == 'a');
			if(dp[i][j-1] > dp[i-1][j]){
				dp[i][j]=  dp[i][j-1] + (arr[i][j] == 'a');
			} 
		}
	}
	if(dp[n][n] + k>=2*n-1){
		forj(2*n-1)
			cout<<'a';
		return;
	}
	int mx = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i+j-1== dp[i][j]+k)
				mx = max(mx, dp[i][j]+k);
	vector<pair<int,int> > cand;
	if(!mx)
		cand.pb(mp(0,1)), seen[0][1] = 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i+j-1 == dp[i][j] + k && mx == dp[i][j]+k){
				cand.pb(mp(i,j));
				seen[i][j] = 1;	
			}
	string ini = "";
	forj(mx)
		ini+='a';
	for(int i = mx; i<2*n-1; i++){
		char mn = 'z';
		vector<pair<int,int> > new_cand;
		forj(cand.size()){
			int x = cand[j].ff, y = cand[j].ss;
			mn = min(mn,arr[x+1][y]);
			mn = min(mn,arr[x][y+1]);
		}
		forj(cand.size()){
			int x = cand[j].ff, y = cand[j].ss;
			if(arr[x+1][y] == mn && !seen[x+1][y]){
				seen[x+1][y] = 1;
				new_cand.pb(mp(x+1,y));
			}
			if(arr[x][y+1] == mn && !seen[x][y+1]){
				seen[x][y+1] = 1;
				new_cand.pb(mp(x,y+1));
			}
		}
		ini+=mn;
		cand = new_cand;
	}
	cout<<ini;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 
11 9 10
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
8 10 
8 11

*/