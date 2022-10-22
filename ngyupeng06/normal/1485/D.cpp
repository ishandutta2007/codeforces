#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

int n, m, a;
int b = 16 * 9 * 5 * 7 * 11 * 13;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> a;
			if ((i+j)%2 == 0) cout << b << " ";
			else cout << b + a*a*a*a << " ";
		}
		cout << "\n";
	}
}