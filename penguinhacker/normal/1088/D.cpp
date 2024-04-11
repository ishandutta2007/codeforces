#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int qry(int c, int d) {
	cout << "? " << c << " " << d << endl;
	int x; cin >> x;
	assert(x!=-2);
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c=0, d=0;
	int res=qry(0, 0);
	for (int i=29; i>=0; --i) {
		int last=res;
		c^=(1<<i), d^=(1<<i);
		res=qry(c, d);
		if (last!=res) {
			assert(abs(res)==1&&abs(last)==1);
			if (last==1) {
				d^=(1<<i);
			}
			else {
				c^=(1<<i);
			}
			res=qry(c, d);
		}
		else {
			last=res;
			d^=(1<<i);
			res=qry(c, d);
			if (res==1) {
				c^=(1<<i);
			}
			else {
				d^=(1<<i);
			}
			res=last;
		}
	}
	cout << "! " << c << " " << d << "\n";
	return 0;
}