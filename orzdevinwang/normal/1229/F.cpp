#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7;
int n, mtt = 20, a[N];
ll l[N], r[N], ml[N], mr[N];
priority_queue < ll > ql;
priority_queue < ll, vector < ll >, greater < ll > > qr;
ll check(ll x) {
	ll lec = -2e10, ret = 0;
	L(i, 1, n) ml[i] = l[i], mr[i] = r[i];
	ml[1] -= x, mr[1] -= x;
	ml[n] += x, mr[n] += x;
	while(!ql.empty()) ql.pop();
	while(!qr.empty()) qr.pop();
	ll tagl = 0, tagr = 0;
	L(t, 1, n) ql.push(0), qr.push(0), ret -= lec; 
	L(i, 1, n) {
		lec += ml[i];
		ret += abs(lec);
		
		tagl += ml[i];
		tagr += mr[i];
		
		ql.push(-tagl), qr.push(-tagr);
		while(ql.top() + tagl > qr.top() + tagr) {
			ll x = ql.top() + tagl, y = qr.top() + tagr;
			ql.pop(), qr.pop();
			ql.push(y - tagl), qr.push(x - tagr);
		}
		
//		cout << ql.top() + tagl << " and " << qr.top() + tagr << '\n';
	}
//	cout << lec << " : " << ret << '\n';
	
	ret += lec * n;
	ret += lec * n;
	
	while(sz(ql)) {
		ll w = ql.top() + tagl;
		if(w < 0) ret += -w;
		ql.pop();
	}
//		ret += lec - (ql.top() + tagl), ql.pop();

	while(sz(qr)) {
		ll w = qr.top() + tagr;
		if(w < 0) ret += -w;
		qr.pop();
	}
	 
	return ret + abs(x);
} 
int main () { 
//	freopen("ex_c2.in", "r", stdin);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		ll x;
		cin >> x;
		cin >> l[i] >> r[i];
		l[i] -= x, r[i] -= x;
	}
//	cout << check(0) << '\n';
//	return 0;
	ll l = -2e9, r = 2e9, ns = 1e18;
	while(l + 1 < r) {
		ll mid1 = (l + r) >> 1, mid2 = mid1 + 1;
		ll ns1 = check(mid1), ns2 = check(mid2);
		if(ns1 < ns2) r = mid2 - 1;
		else l = mid1 + 1;
		ns = min(ns, ns1), ns = min(ns, ns2);
	} 
	L(i, l, r) ns = min(ns, check(i));
	cout << ns << '\n';
	return 0;
}
/*
2
0 1 1
1 0 1
*/