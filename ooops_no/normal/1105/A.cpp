/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;



int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int mns = 10e5;
	int rm;
	for (int i = 1; i <= 100; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int a = v[j];
			if (a == i) {
				continue;
			}
			cnt += min(abs(a + 1 - i), abs(a - 1 - i));
		}
		if (cnt < mns) {
			rm = i;
			mns=cnt;
		}
	}
	cout << rm << ' ' << mns;
}