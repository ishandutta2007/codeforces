#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int AL= 26;
const int N = 1009;
const ll MOD= (ll)1e9 + 7;

int maxs[AL];
int dp[N];
int siz[N];
char v[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++)
		cin >> v[i];
	for(int j = 0;j<AL;j++){
		cin >> maxs[j];
	}
	int cl,al;
	dp[0] = 1;
	int av = 0;
	for(int x = 1;x<=n;x++){
		cl = 0;
		al = (int)1e9 + 9;
		siz[x] = (int)1e9 + 9;
		for(int y = x;y>=1;y--){
			cl++;
			al = min(al,maxs[v[y]-97]);
			if(cl > al)
				break;
			dp[x] += dp[y-1];
			dp[x] %= MOD;
			siz[x] = min(siz[x],siz[y-1]+1);
			av = max(av,cl);
		}
	}
	cout << dp[n] << "\n" << av << "\n"<< siz[n] << "\n" ;
	return 0;
}