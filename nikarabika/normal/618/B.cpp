//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

bool mark[100];
int a[100][100], cnt[100][100];
int ans[100];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			cnt[i][a[i][j]]++;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int ii = 1; ii <= n; ii++)
			if(!mark[ii] and cnt[ii][i] == n - i){
				mark[ii] = true;
				ans[ii] = i;
				break;
			}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	return 0;
}