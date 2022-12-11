#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define PB push_back
#define MP make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 30;
bool v[maxn][maxn];
int n;
pair<int, char> x[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> n;
	cin >> s;
	n --;
	rep(i, n){
		cin >> t;
		int p = 0;
		while(p < min(s.size(), t.size()) and s[p] == t[p])
			p++;
		if(p == t.size()){
			cout << "Impossible" << endl;
			return 0;
		}
		if(p == s.size())
			continue;
		int x = s[p] - 'a' + 1;
		int y = t[p] - 'a' + 1;
		//cerr << x << ' ' << y << endl;
		v[x][y] = true;
		reu(j, 1, 26){
			if(v[y][j]){
				v[x][j] = true;
				reu(k, 1, 26)
					if(v[k][x])
						v[k][j] = true;
			}
		}
		reu(j, 1, 26){
			if(v[j][x]){
				v[j][y] = true;
				reu(k, 1, 26)
					if(v[y][k])
						v[j][k] = true;
			}
		}
		s = t;
	}
	reu(j, 1, 26){
		reu(i, 1, 26){
			if(v[i][j] and v[j][i]){
				cout << "Impossible" << endl;
				return 0;
			}
			if(v[i][j])
				x[j].p1 ++;
		}
		x[j].p2 = j + 'a' - 1;
	}
	sort(x+1, x+26+1);
	reu(i, 1, 26)
		cout << x[i].p2;
	cout << endl;
	return 0;
}