#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, u, v, a, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	while (m--){
		cin >> n >> u >> v;
		b = -1;
		bool gd = true, gd2=true;
		for (int i=0; i<n; i++){
			cin >> a;
			if (b!=a && b!=-1) gd=false;
			if (abs(a-b) > 1 && b!=-1) gd2 = false;
			b=a;
		}
		if (!gd2) cout << 0 << "\n";
		else if (gd) cout << min(u+v, 2*v);
		else cout << min(u,v);
		cout << "\n";
	}
}