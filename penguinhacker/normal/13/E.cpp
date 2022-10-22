#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000, BLOCK=400;
int n, m, power[mxN];
int b[mxN], nxt[mxN], jump[mxN];

void qry(int source) {
	int totJump=0;
	int last;
	while(1) {
		totJump+=jump[source];
		if (nxt[source]>=n) { //find last hole before ball jumps out of row
			while(source<n) {
				last=source;
				source+=power[source];
			}
			break;
		}
		source=nxt[source];
	}
	cout << last+1 << ' ' << totJump << '\n';
}

inline bool same(int i, int j) {return j<n&&b[i]==b[j];}
void comp(int i) {
	assert(i<n);
	int j=i+power[i];
	if (same(i, j)) {
		jump[i]=jump[j]+1;
		nxt[i]=nxt[j];
	}
	else {
		jump[i]=1;
		nxt[i]=j;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> power[i], b[i]=i/BLOCK;
	for (int i=n-1; ~i; --i) comp(i);
	/*for (int i=0; i<n; ++i)
		cout << jump[i] << ' ' << nxt[i] << '\n';
	cout << '\n';*/
	while(m--) {
		int type, source;
		cin >> type >> source, --source;
		if (type==1) qry(source);
		else {
			int x; cin >> x;
			power[source]=x;
			comp(source);
			for (int i=source-1; i>=0&&b[source]==b[i]; --i)
				comp(i);
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/