#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define inf 2e9

li n, i, j, k, a, b, c, sum, t, cmax=2e16, cmin=-2e16;
bool ch, good;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (i=0; i<n; i++){
		cin >> a >> b;
		if (b==2){
			if (cmin>1899){
				ch=1;
				break;
			}
			if (cmax>1899) cmax=1899;
			cmax = cmax+a;
			cmin+=a;
		}
		if (b==1){
			if (cmax<1900){
				ch = 1;
				break;
			}
			if (cmin<1900) cmin=1900;
			cmin += a;
			cmax+=a;
		}
	}
	if (ch==1) cout << "Impossible";
	else if (cmax>=2e10) cout << "Infinity";
	else cout << cmax;
}