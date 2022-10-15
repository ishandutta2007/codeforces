#include <iostream>
#include <cstdlib>

using namespace std;

int n;
bool ready[101010];
int val[101010];

int query(int k) {
	if (k > n) k -= n;
	if (ready[k]) return val[k];
	cout << "? " << k << endl;
	ready[k] = 1;
	cin >> val[k];
	return val[k];
}

void find(int a1, int b1, int a2, int b2) {
	int x1 = query(a1);
	int x2 = query(a2);
	if (x1 == x2) {
		cout << "! " << a1 << endl;
		exit(0);
	}
	int w = (b1-a1+1)/2;
	int y1 = query(a1+w);
	int y2 = query(a2+w);
	if (y1 == y2) {
		cout << "! " << a1+w << endl;
		exit(0);
	}
	bool z = 0;
	if (x1 > x2 && y1 > y2) z = 1;
	if (x1 < x2 && y1 < y2) z = 1;
	if (z == 0) {
		find(a1,a1+w-1,a2,a2+w-1);
	} else {
		find(a1+w,b1,a2+w,b2);
	}
}

int main() {
	cin >> n;
	if (n%4 == 2) {
		cout << "! -1" << endl;
		return 0;
	}
	find(1,n/2,n/2+1,n);
}