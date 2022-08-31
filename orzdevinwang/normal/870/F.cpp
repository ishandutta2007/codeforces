#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
using namespace std;
const int N = 1e7 + 7;
int n, m;
bool Prime[N];
int p[N >> 3], phi[N], mns[N], pin[N], tot, tnt[N];
void xxs(int x) {
	phi[1] = 1;
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i, phi[i] = i - 1, pin[i] = 1;
		for(int j = 1; j <= tot && p[j] * i <= x; j++) {
			Prime[p[j] * i] = 1, mns[p[j] * i] = p[j], pin[p[j] * i] = pin[i] + 1, tnt[p[j]]++;
			if(i % p[j] == 0) {
				phi[p[j] * i] = phi[i] * p[j], pin[p[j] * i] --;
				break;
			}
			phi[p[j] * i] = phi[i] * (p[j] - 1);
		}
	}
}
ll ns;
int main() {
	cin >> n, xxs(n);
	
	int n2 = 0;
	L(i, 1, tot) if(p[i] * 2 <= n) n2 = i;
	ns += (ll) 3 * n2 * (n2 - 1) / 2;
	L(i, 1, tot) L(j, i + 1, tot) {
		if((ll) p[i] * p[j] > n) break;
		ns --;
	}
	int hs = 0;
	L(i, 2, n) if(Prime[i]) ++hs, ns -= i - phi[i] - pin[i] - 1;
	ns += (ll) hs * (hs - 1);
	ns += (ll) n2 * hs * 3;
	L(i, 1, tot) L(j, 1, tot) {
		if((ll) p[i] * p[j] > n) break;
		ns -= tnt[p[j]];
	}
	L(i, 1, tot) {
		for(int j = p[i] * 2; j <= n; j += p[i]) {
			if((ll) mns[j] * p[i] <= n) ns--;
			else ns++;
		}
	}
	cout << ns << "\n";
    return 0;
}