#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int ll;
typedef pair<int, vector<int> > Que;

const int maxn = 1e5 + 10;
Que f[maxn];
ll val[10][maxn], dig[10][maxn], P[(int)1e6];
const ll D = 1e9 + 7;
int n;

ll pow(ll p){
	if(p < (ll)1e6)
		return P[p];
	ll x = pow(p >> 1);
	x *= x;
	x %= D;
	if(p & 1)
		x *= 10;
	return x % D;
}

void input(){
	string s;
	cin >> s;
	vector<int> v;
	v.reserve(100000);
	for(int i = 0; i < s.size(); i++)
		v.PB(s[i] - '0');
	f[0] = MP(1, v);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		v.clear();
		for(int j = 3; j < s.size(); j++)
			v.PB(s[j] - '0');
		f[i] = MP(s[0] - '0', v);
	}

	P[0] = 1;
	for(int i = 1; i < 1e6; i++)
		P[i] = (P[i - 1] * 10) % D;
}

ll value(vector<int> v){
	ll ans = 0;
	for(int i = 0; i < v.size(); i++)
		ans = (ans * 10 + v[i]) % D;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	input();
	for(int i = 0; i < 10; i++){
		if(i != f[n].L){
			val[i][n] = i;
			dig[i][n] = 1;
			continue;
		}
		val[i][n] = value(f[n].R);
		dig[i][n] = (ll)f[n].R.size();
	}
	for(int j = n - 1; j >= 0; j--){
		for(int i = 0; i <= 9; i++){
			if(i != f[j].L){
				val[i][j] = val[i][j + 1];
				dig[i][j] = dig[i][j + 1];
				continue;
			}
			ll m = 0;
			vector<int> v = f[j].R;
			for(int ii = v.size() - 1; ii >= 0; ii--){
				val[i][j] += val[v[ii]][j + 1] * pow(m);
				val[i][j] %= D;
				m += dig[v[ii]][j + 1];
				m %= D - 1;
			}
			dig[i][j] = m;
		}
	}
	cout << val[1][0] << endl;
	return 0;
}