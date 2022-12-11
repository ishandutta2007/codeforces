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

int main(){
	fastIO;
	int n,s;
	cin >> n >> s;
	int ans = 0;
	int f,t;
	for(int i = 0;i<n;i++){
		cin >> f >> t;
		ans = max(ans, max(t,(s - f)) + f);
	}
	cout << ans << "\n";
	return 0;
}