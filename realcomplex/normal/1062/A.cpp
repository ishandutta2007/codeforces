#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;

int a[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	a[0] = 0;
	a[n + 1] = 1001;
	for(int i = 1 ; i <= n; i ++  ){
		cin >> a[i];
	}
	int tot = 0;
	int ans = 0;
	for(int i = 1; i <= n; i ++ ){
		tot = 0;
		for(int j = i; j <= n; j ++ ){
			tot ++ ;
			if(a[j + 1] - a[i - 1] - 1 == tot){
				ans = max(ans, tot);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}