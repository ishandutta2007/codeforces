#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 1e5 + 10;
ll a[maxn], sv[maxn], su[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sv[i] = sv[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		su[i] = su[i - 1] + a[i];
	cin >> m;
	while(m--){
		int fi, se, th;
		cin >> fi >> se >> th;
		if(fi == 1)
			cout << sv[th] - sv[se - 1] << endl;
		else
			cout << su[th] - su[se - 1] << endl;
	}
	return 0;
}