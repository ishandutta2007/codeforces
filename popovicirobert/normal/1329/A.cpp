#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n >> m;
   	vector<int> len(m + 1);
   	vector<int> sp(m + 2);
   	for(i = 1; i <= m; i++) {
   		cin >> len[i];
   		if(i - 1 + len[i] > n) {
   			cout << -1;
   			return 0;
   		}
   	}
   	ll s = 0;
   	for(i = m; i >= 1; i--) {
   		sp[i] = max(i + len[i], sp[i + 1]);
   		s += len[i];
   	}
   	if(s < n) {
   		cout << -1;
   		return 0;
   	}
   	int l = 1, r = 1;
   	for(i = 1; i <= m; i++) {
   		while(l <= r && l + sp[i] - i - 1 <= n) {
   			l++;
   		}
   		l--;
   		cout << l << " ";
   		r = max(r, l + len[i]);
   		l++;
   		if(l > r) {
   			r = l;
   		}
   	}

    return 0;
}