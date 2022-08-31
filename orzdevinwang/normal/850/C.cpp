#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, B = 33333;
map<int, int> mp;
int bfs(int msk) {
	if(msk & 1) msk ^= 1;
	if(msk == 0) return 0;
//	cout << msk << "\n";
	if(mp.count(msk)) return mp[msk];
	unsigned int m = 0; 
	L(i, 1, 30) {
		if(msk < (1 << i)) break;
//		cout << "qwq ! \n";
		m |= (1 << bfs((msk & ((1 << i) - 1)) | (msk >> i))); 
	}
//	cout << msk << " : " << m << " " << __builtin_ctz(~m) << "\n";
	return mp[msk] = __builtin_ctz(~m);
}
int n, s[N], a[N], ns;
map<int, int> used;
int main() {
	bfs(1);
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 2, B) {
		L(j, 1, n) s[j] = 0;
		int o = 0;
		L(j, 1, n) while(a[j] % i == 0) s[j] ++, a[j] /= i;
		L(j, 1, n) o |= (1 << s[j]); 
		ns ^= bfs(o);
	}
	L(i, 1, n) if(a[i] > 1 && !used[a[i]]) used[a[i]] = 1, ns ^= 1;
	cout << (!ns ? "Arpa" : "Mojtaba") << "\n";
	return 0;
}