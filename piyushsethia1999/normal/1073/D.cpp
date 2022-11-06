#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int seg1[800000];
int seg2[800000];
int defval = 0;
int n;
pair<int, int> a[200000];

void helperbuild(int node, int s, int e) {
	if (s == e) { seg1[node] = a[s].first; return; }
	int m = (s + e) >> 1;
	helperbuild(2 * node, s, m);
	helperbuild(2 * node + 1, m + 1, e);
	seg1[node] = seg1[2 * node] + seg1[2 * node + 1];
}
void build() {
	helperbuild(1, 0, n - 1);
}
void pointupdate(int i, int& val, int s = 0, int e = n - 1, int node = 1) {
	if (s > i || i > e) { return; }
	if (s == e) { seg1[node] = val; return; }
	int m = (s + e) >> 1;
	pointupdate(i, val, s, m, 2 * node);
	pointupdate(i, val, m + 1, e, 2 * node + 1);
	seg1[node] = seg1[2 * node + 1] + seg1[2 * node];
}
int query(int l, int r, int node = 1, int s = 0, int e = n - 1)
{
	if (s > r || e < l) return defval;
	if (l <= s && e <= r) return seg1[node];
	int m = (s + e) >> 1;
	return query(l, r, 2 * node, s, m) + query(l, r, 2 * node + 1, m + 1, e);
}

int que(int s, int e)
{
	if (e >= s)
		return query(s, e);
	return query(0, e) + query(s, n - 1);
}

void helperbuild1(int node, int s, int e) {
	if (s == e) { seg2[node] = a[s].second; return; }
	int m = (s + e) >> 1;
	helperbuild1(2 * node, s, m);
	helperbuild1(2 * node + 1, m + 1, e);
	seg2[node] = seg2[2 * node] + seg2[2 * node + 1];
}
void build1() {
	helperbuild1(1, 0, n - 1);
}
void pointupdate1(int i, int& val, int s = 0, int e = n - 1, int node = 1) {
	if (s > i || i > e) { return; }
	if (s == e) { seg2[node] = val; return; }
	int m = (s + e) >> 1;
	pointupdate1(i, val, s, m, 2 * node);
	pointupdate1(i, val, m + 1, e, 2 * node + 1);
	seg2[node] = seg2[2 * node + 1] + seg2[2 * node];
}
int query1(int l, int r, int node = 1, int s = 0, int e = n - 1)
{
	if (s > r || e < l) return defval;
	if (l <= s && e <= r) return seg2[node];
	int m = (s + e) >> 1;
	return query1(l, r, 2 * node, s, m) + query1(l, r, 2 * node + 1, m + 1, e);
}


int que1(int s, int e)
{
	if (e >= s)
		return query1(s, e);
	return query1(0, e) + query1(s, n - 1);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	cin >> n;
	int T;
	cin >> T;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = 1;
	}
	build();
	build1();

	int pst = n;
	int costt = que(0, n - 1);

	int pos = 0;

	int cnt = 0;

	while (pst != 0) {
		int tcost = costt;
		cnt += (pst) * (T / tcost);
		T = T % tcost;
		int s = 0;
		int e = n - 1;
		while (s < e) {
			int m = (s + e) / 2;
			tcost = que(pos, (pos + m) % n);
			if (tcost <= T)
				s = m + 1;
			else
				e = m;
		}
		pst--;
		costt -= a[(pos + s) % n].first;
		if (s != 0)
		{
			T -= que(pos, (pos + s - 1) % n);
			cnt += que1(pos, (pos + s - 1) % n);
			pos = (pos + s) % n;
			pointupdate(pos, defval);
			pointupdate1(pos, defval);
		}
		else {
			pointupdate(pos, defval);
			pointupdate1(pos, defval);
		}
	}
	cout << cnt;
}