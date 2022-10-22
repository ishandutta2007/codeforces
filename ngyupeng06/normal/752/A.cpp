#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back

li n, m, k, x, y, z;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	x = (k-1)/(2*m)+1;
	y = ((k-1)%(2*m))/2+1;
	z = ((k-1)%(2*m))%2;
	cout << x << " " << y;
	if (z==0) cout << " L";
	else cout << " R";
}