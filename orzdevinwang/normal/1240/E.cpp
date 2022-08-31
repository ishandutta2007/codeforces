#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, M = 1e6, rM = 5e5; 
int n, a[N], cnt[N], sum[N];

struct Data {
	int mn1, mn2;
	Data (int m1 = 0, int m2 = 0) { mn1 = m1, mn2 = m2; }
	void insert (int i) {
		if(mn1 > i) mn2 = mn1, mn1 = i;
		else if(mn2 > i) mn2 = i;
	}
	friend Data operator + (Data a, Data o) {
		Data ns = a;
		ns.insert(o.mn1);
		ns.insert(o.mn2);
		return ns;
	}
};
Data ls[N], lt[N];

ll ret = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cnt[a[i]] += 1;
	ls[0] = Data (1e9, 1e9);
	L(i, 1, M) {
		ls[i] = Data(ls[i - 1].mn1 + 1, ls[i - 1].mn2 + 1);
		L(j, 1, cnt[i]) ls[i].insert(0);
	}
	R(i, M, 1) sum[i] = cnt[i] + sum[i + 1];
	L(i, 2, rM) {
		ll cnt = 0;
		for (int j = i; j <= M; j += i) cnt += sum[j];
		for (int j = M / i * i; j >= i; j -= i) {
			lt[j] = ls[j - 1];
			if(j + i <= M) lt[j] = lt[j] + lt[j + i];
		} 
		
		int l = 2, r = rM, ns = 0;
		while (l <= r) {
			int mid = (l + r) >> 1, tmid = mid * 2;
			ll z = cnt - (mid / i) * 2, cz = cnt - tmid / i, c = mid % i, cc = tmid % i;
			
			if(sum[mid] < 2) z = -1;
			else {
				Data h (1e9, 1e9);
				int CH = i * (mid / i + 1);
				if(CH - ls[CH - 1].mn1 >= mid) h.mn1 = ls[CH - 1].mn1; 
				if(CH - ls[CH - 1].mn2 >= mid) h.mn2 = ls[CH - 1].mn2; 
				if(CH + i <= M) h = h + lt[i + CH];
				if(h.mn1 + c >= i) z -= 1;
				if(h.mn2 + c >= i) z -= 1;
			}
			
			if(sum[tmid] < 1) cz = -1; 
			else { 
				Data h = Data (1e9, 1e9);
				ll CH = i * (tmid / i + 1);
				if(CH - ls[CH - 1].mn1 >= tmid) h.mn1 = ls[CH - 1].mn1; 
				if(CH - ls[CH - 1].mn2 >= tmid) h.mn2 = ls[CH - 1].mn2; 
				if(CH + i <= M) h = h + lt[i + CH];
				if(h.mn1 + cc >= i) cz -= 1;
				z = max(z, cz);
			}
			
			if (z >= mid) ns = mid, l = mid + 1;
			else r = mid - 1;
		}
		ret = max(ret, (ll) ns * i);
	}
	cout << ret << '\n';
	return 0;
}