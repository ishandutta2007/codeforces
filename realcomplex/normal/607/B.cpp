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

const int maxn = 509;
int rem[maxn][maxn];
int col[maxn];

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> col[i];
		rem[i][i] = 1;
	}
	for(int i= 1;i<=n;i++){
		for(int j= 1;j<=i;j++){
			rem[j][i] = rem[j][i-1]+1;
			for(int k = j;k<i;k++){
				if(col[k] == col[i]){
					rem[j][i] = min(rem[j][i],rem[j][k-1]+max(1,rem[k+1][i-1]));
				}
			}
		}
	}
	cout << rem[1][n] << "\n";
	return 0;	
}