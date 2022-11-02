#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

const int MAX_N = 1e6 + 100;

int tab[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int res = 0;
    int ciag = 0;
    int suma = 0;
    
    for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		
		if (c == '0') {
			for (int j = 1; j <= ciag; j++) {
				suma += j;
				tab[j]++;
			}
			tab[0]++;
			ciag = 0;
			res += suma;
		} else {
			cerr << suma << " " << ciag << endl;
			suma += tab[ciag];
			tab[ciag + 1] += tab[ciag];
			tab[ciag] = 0;
			ciag++;
			cerr << suma << " " << ciag << endl;
			
			res += suma + ciag * (ciag + 1) / 2;
		}
		
		cerr << res << endl;
	}
	
	cout << res;
    
    
    return 0;
}/*

*/