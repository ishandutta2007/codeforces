#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxP=3e6;
vector<bool> pos(mxP, 1); //possible numbers
void ridPrime(int p) {
	for (int i=p; i<mxP; i+=p) {
		pos[i]=0;
	}
}

void doStuff(int x) {
	set<int> p_f;
	for (int i=2; i*i<=x; ) {
		if (x%i==0) {
			x/=i;
			p_f.insert(i);
		}
		else ++i;
	}
	if (x>1)
		p_f.insert(x);
	for (const int &i : p_f) {
		ridPrime(i);
	}
}

int n, l=2;
bool g=0; //greater

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		if (!g&&pos[a]) {
			cout << a << ' ';
			doStuff(a);
		}
		else if (!g) {
			g=1;
			while(pos[a]==0)
				++a;
			cout << a << ' ';
			doStuff(a);
		}
		else {
			assert(l<mxP);
			while (pos[l]==0)
				++l;
			cout << l << ' ';
			doStuff(l);
			continue;
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