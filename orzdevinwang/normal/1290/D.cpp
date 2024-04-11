#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20;
int n, k, B, cB, bl[N], br[N];
bool ok[N]; //  
char s[N];
int ask (int x) {
	cout << "? " << x << endl;
	cin >> (s + 1);
	if(s[1] == 'N') return false;
	return ok[x] = true;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> k, B = k, cB = n / B;
	L(i, 1, cB) bl[i] = (i - 1) * B + 1, br[i] = B * i;
	L(i, 1, cB) {
		cout << "R" << endl;
		int le = 0, ri = 0, k = i;
		L(j, 1, cB) {
			L(x, bl[k], br[k]) if(!ok[x]) ask (x);
			if(le <= ri) ++le, k = (i + le - 1) % cB + 1;
			else ++ri, k = (i - ri + cB - 1) % cB + 1;
		}
	}
	int cnt = 0;
	L(i, 1, n) cnt += !ok[i];
	cout << "! " << cnt << endl;
	return 0;
}