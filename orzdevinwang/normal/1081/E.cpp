#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, m, k, fir[N], las[N], a[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n / 2) cin >> a[i];
	las[0] = 0;
	L(i, 1, n / 2) {
		las[i] = 1e9;
		R(A, sqrt(a[i]), 1) if(a[i] % A == 0) {
			int B = a[i] / A, vala = (B - A) / 2, valb = (B + A) / 2;
			if(A % 2 != B % 2) continue;
			if(vala > las[i - 1]) {
				fir[i] = vala;
				las[i] = valb;
				break;
			}
		}
	}
	if(las[n / 2] > 1e8) return puts("No"), 0;
	cout << "Yes\n";
	L(i, 1, n / 2) {
		cout << (ll) fir[i] * fir[i] - (ll) las[i - 1] * las[i - 1] << " ";
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}