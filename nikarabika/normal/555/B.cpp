#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pie;

#define MP make_pair
#define L first
#define R second

const int maxn = 2e5 + 85 - 69;
pair<pie, LL> sect[maxn];
pie is[maxn];
set<pie> s;
LL n, m, f[maxn];

bool cmp(pair<pie, LL> x, pair<pie, LL> y){
	if(x.L.R == y.L.R)
		return x.L.L < y.L.L;
	return x.L.R < y.L.R;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> is[i].L >> is[i].R;
	for(int i = 0; i < n - 1; i++)
		sect[i] = MP(MP(is[i + 1].L - is[i].R, is[i + 1].R - is[i].L), i);
	n--;
	sort(sect, sect + n, cmp);
	for(LL i = 0; i < m; i++){
		LL x;
		cin >> x;
		s.insert(MP(x, i + 1));
	}
	for(int i = 0; i < n; i++){
		if(s.lower_bound(MP(sect[i].L.L, 0)) == s.end()){
			cout << "No" << endl;
			return 0;
		}
		pie x = *s.lower_bound(MP(sect[i].L.L, 0));
		if(x.L > sect[i].L.R){
			cout << "No" << endl;
			return 0;
		}
		f[sect[i].R] = x.R;
		s.erase(MP(x.L, x.R));
	}
	cout << "Yes\n";
	for(int i = 0; i < n; i++)
		cout << f[i] << ' ';
	cout << endl;
	return 0;
}