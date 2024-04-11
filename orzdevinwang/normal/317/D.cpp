#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
// int f[N];
// map<int, int> mp;
// int dfs(int n, int has) {
// 	if(has == 0) return 0;
// 	if(mp.count(has)) return mp[has];
// 	vector<int> ve;
// 	int sav = has;
// 	L(i, 1, n) if(has & (1 << (i - 1))) {
// 		L(j, 1, n / i) if(has & (1 << (j * i - 1))) has ^= (1 << (j * i - 1));
// 		ve.push_back(dfs(n, has));
// 		has = sav;
// 	}
// 	sort(ve.begin(), ve.end());
// 	int SG = 0;
// 	for(int x : ve) if(x > SG) break; else SG = x + 1;
// 	return mp[has] = SG;
// }
int n, SG[N] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
int cnt, flag[N], ans = 1;
int main() {
	// L(i, 1, 30) {
	// 	SG[i] = dfs(i, (1 << i) - 1);
	// 	cout << SG[i] << "\n";
	// 	mp.clear();
	// }
	// puts("");
	scanf("%d", &n);
	int B = sqrt(n);
	// int B = n;
	cnt = n - B;
	L(i, 2, B) if(!flag[i]) {
		// cout << "work on" << i << endl;
		int tt = 0, now = i;
		while(now <= n) {
			tt++;
			if(now <= B) flag[now] = 1;
			else cnt --; //, cout << now << endl;
			if(now > n / i + 1) break;
			now *= i;
		}
		// cout << i << " " << tt << " " << SG[tt] << endl;
		ans ^= SG[tt];
	}
	// cout << cnt << endl;
	if(cnt & 1) ans ^= 1;
	if(!ans) puts("Petya");
	else puts("Vasya");
	return 0;
}