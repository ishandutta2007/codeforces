#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back

li sum, n, i, j, c, k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	c = 240-k;
	for (i=1; i<=n; i++){
		sum+=5*i;
		if (sum>c){
			cout << i-1;
			break;
		}
		if (i==n) cout << n;
	}
}