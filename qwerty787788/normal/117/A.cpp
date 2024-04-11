#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
//#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
int n, m;
int s, f, t, t1, add_time;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s >> f >> t;
		if (s < f) {
			t1 = t%(2*(m-1));
			add_time = 0;
			if (t1 > (s-1)) {
				add_time = 2*(m-1)-t1;
				t1 = 0;
			}
			add_time += (s-1-t1) + (f-s);
			cout << (add_time + t) << endl;
		} else {
			if (s==f) {
				cout << t << endl;
			} else {
				t1=(t-m+1)%(2*(m-1));
				add_time = 0;
				if (s > m-t1) {
					add_time = 2*(m-1)-t1;
					t1 = 0;
				}
				add_time+= (m-t1-s) + (s-f);
				cout << (add_time+t) << endl;
			}
		}
	}
	//
	return 0;
}