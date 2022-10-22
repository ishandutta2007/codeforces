#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, t, a, b, c, d;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> a >> b >> c >> d;
		long long x = (a-b)*n;
		long long y = (a+b)*n;
		bool gd = true;
		if (x >= c-d && x <= c+d) gd = true;
		else if (y <= c+d && y >= c-d) gd = true;
		else if (x <= c-d && y >= c+d) gd = true;
		else gd = false;
		if (gd) cout << "Yes\n";
		else cout << "No\n";
	}
}