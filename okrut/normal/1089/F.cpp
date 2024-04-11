#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf

typedef long long ll;
typedef pair<int, int> pii;

const int duzo = 100007;
bool cp[duzo];

int main()
{
	for(int i = 2; i < duzo; ++i) {
		if(!cp[i]) for(int j = 2 * i; j < duzo; j += i) cp[j] = true;
	}
	int n;
	cin >> n;
	bool czyp = true;
	vector<int> dz; 
	for(int i = 2; i * i <= n; ++i) {
		if(!cp[i] && n % i == 0) {
			dz.pb(i);
			if((int)dz.size() >= 2) break;
			czyp = false;
			int robn = n;
			while(robn % i == 0) robn /= i;
			if(robn == 1) {
				czyp = true;
				break;
			}
		}
	}
	if(czyp) {
		cout << "NO";
		return 0;
	}
	if((int)dz.size() == 1) {
		int robn = n;
		while(robn % dz[0] == 0) robn /= dz[0];
		dz.pb(robn);
	}
	int p1 = dz[0], p2 = dz[1], a, b;
	for(int i = 1; i < p1; ++i) {
		if((n - 1 - i * p2) % p1 == 0) {
			b = i;
			a = (n - 1 - i * p2) / p1;
			break;
		}
	}
	cout << "YES\n2\n" << a << " " << n / p1 << "\n" << b << " " << n / p2;
	return 0;
}