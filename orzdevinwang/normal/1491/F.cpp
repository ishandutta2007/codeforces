#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2333;
int n, f[N], las, g[N], gtot;
void Main() {
	cin >> n;
	L(i, 2, n) {
		cout << "? 1 " << i - 1 << endl << i << endl;
		L(j, 1, i - 1) cout << j << " ";
		cout << endl, fflush(stdout);
		int k; cin >> k;
		if(k) {
			las = i;
			break;
		}
	}
	int l = 1, r = las - 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		cout << "? 1 " << mid - l + 1 << endl << las << endl;
		L(i, l, mid) cout << i << " ";
		cout << endl;
		int k; cin >> k;
		if(k) r = mid;
		else l = mid + 1;
	}
	gtot = 0;
	L(i, 1, las - 1) if(i != l) g[++gtot] = i;
	L(i, las + 1, n) {
		cout << "? 1 1" << endl << las << endl << i << endl;
		int k; cin >> k;
		if(!k) g[++gtot] = i;
	}
	cout << "! " << gtot << " ";
	L(i, 1, gtot) cout << g[i] << " ";
	cout << endl;
	fflush(stdout);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int T; cin >> T;
	while(T--) Main();
	return 0;
}