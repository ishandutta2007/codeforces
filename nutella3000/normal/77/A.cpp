#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;

bool gr[10][10];
int b[3];
int a[10];
int cnt[3];

int r1 = inf, r2 = 0;

void rec(int id) {
	//cout << id << endl;
	if (id == 7) {
		if (min({cnt[0], cnt[1], cnt[2]}) == 0) return;
		int a1 = b[0] / cnt[0], a2 = b[1] / cnt[1], a3 = b[2] / cnt[2];
		int nr1 = max({a1, a2, a3}) - min({a1, a2, a3}), nr2 = 0;
		
		for(int i = 0;i < 7;i++) {
			for(int j = 0;j < 7;j++) {
				if (gr[i][j] && a[i] == a[j]) nr2++;
			}
		}
		if (r1 > nr1 || (r1 == nr1 && r2 < nr2)) {
			r1 = nr1;
			r2 = nr2;
		}
		return;
	}
	for(int i = 0;i < 3;i++) {
		cnt[i]++;
		a[id] = i;
		rec(id + 1);	
		cnt[i]--;
	}
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    //map<string, int> qq = {{"a", 1}, {"b", 2}};
    map<string, int> name {{"Anka", 0}, {"Chapay", 1}, {"Cleo", 2}, {"Troll", 3}, {"Dracul", 4}, {"Snowy", 5}, {"Hexadecimal", 6}};

    int n;
    cin >> n;
  	for(int i = 0;i < n;i++) {
  		string v1, s, v2;
  		cin >> v1 >> s >> v2;
  		gr[name[v1]][name[v2]] = true;
  	}
  	for(int i = 0;i < 3;i++)
  		cin >> b[i];

  	rec(0);
  	cout << r1 << " " << r2;
}