#include <iostream>

using namespace std;

const int N = 1000010;

int Z[N], ans[N];
string str;
int n, k;

int main() {
	
	ios::sync_with_stdio(false);	
	cin >> n >> k;
	cin >> str;

	if(k == 1) {
		for(int i = 0;i < n;i++) {
			cout << 1;
		}
		cout << "\n";
		return 0;
	}

	int mx = 0;
	Z[0] = 0;
	for(int i = 1;i < n;i++) {
		int r = mx + Z[mx] - 1;
		Z[i] = (i > r ? 0 : min(Z[i-mx], r-i+1));
		while(i + Z[i]-1 < n and str[Z[i]] == str[i+Z[i]]) Z[i]++;
		if(i + Z[i] > mx + Z[mx]) mx = i;
	}

	for(int i = 1;i < n;i++) {
		if((i+1) % k == 0) {
			int l = (i + 1) / k;
			bool err = false;
			for(int j = l;j < i+1;j += l) {
				if(Z[j] < l) {
					err = true;
				}
			}
			if(err) continue;

			ans[i]++;
			int x = min(l, min(n-i, Z[i+1]));
			ans[i+x+1]--;
		}
	}

	for(int i = 0;i < n;i++) {
		ans[i] += (i > 0 ? ans[i-1] : 0);
		cout << (ans[i] > 0 ? 1 : 0);
	}

	cout << "\n";

	return 0;
}