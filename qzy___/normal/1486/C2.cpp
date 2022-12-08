#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int check(int l , int r) {
	if(l == r) return -1;
	cout << "?" << " " << l << " " << r << endl;
	cout.flush();
	int x; cin >> x;
	return x;
}

int n;

int main() {
	cin >> n;
	int p = check(1 , n);
	int t1 = check(1 , p);
	if(t1 == p) {
		int l = 1 , r = p - 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid , p) != p)
				r = mid - 1;
			else
				l = mid + 1;
		}
		cout << "! " << r << endl;
	}
	else {
		int l = p + 1 , r = n;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(check(p , mid) == p)
				r = mid;
			else
				l = mid + 1;
		}
		cout <<"! " << l << endl;
	}
}