#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	out << '[' << p.first << ", " << p.second;
	return out << "]\n";
}

int m;
int h1, h2, a, b;
int x1, y1, x2, y2;
pair<int, int> p1, p2;

int calc(int &h, int x, int y, int want) {
	for (int rep=1; rep<=2*m; ++rep) {
		h=(1ll*h*x+y)%m;
		if (h==want) return rep;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	cin >> h1 >> a >> x1 >> y1;
	cin >> h2 >> b >> x2 >> y2;
	p1.first=calc(h1, x1, y1, a); p1.second=calc(h1, x1, y1, a);
	p2.first=calc(h2, x2, y2, b); p2.second=calc(h2, x2, y2, b);
	if (p1.first==-1||p2.first==-1) {
		cout << -1;
		return 0;
	}
	if (p1.second==-1&&p2.second!=-1) {
		cout << (p2.first<=p1.first&&p1.first%p2.second==p2.first%p2.second?p1.first:-1);
		return 0;
	}
	if (p1.second!=-1&&p2.second==-1) {
		cout << (p1.first<=p2.first&&p2.first%p1.second==p1.first%p1.second?p2.first:-1);
		return 0;
	}
	if (p1.second==-1&&p2.second==-1) {
		cout << (p1.first==p2.first?p1.first:-1);
		return 0;
	}
	//cout << p1 << p2;
	ll ans=p1.first;
	bool pos=0;
	for (int i=0; i<2*m; ++i) { //just run enough...
		if (ans>=p2.first&&ans%p2.second==p2.first%p2.second) {
			pos=1;
			break;
		}
		ans+=p1.second;
	}
	cout << (pos?ans:-1);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/