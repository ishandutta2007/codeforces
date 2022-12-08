#include <bits/stdc++.h>
#define int long long

using namespace std;

int T;
int n;
char c[300010];
int sum[300010];

signed main() {
	ios::sync_with_stdio(false); 
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		for(int i = 0; i <= n; i++)
			sum[i] = 0;
		int lst = 1;
		for(int i = 1; i <= n; i++) {
			if(lst == i && c[i] == 'L') {
				lst++;
				continue;
			}
			if(i != lst && c[i] == c[i - 1]) {
				for(int j = lst; j < i; j += 2)
					sum[j - 1] += i - j;
				if(c[i] == 'R')
					lst = i;
				else
					lst = i + 1;
			}
		}
		if(lst != n + 1) {
			for(int i = lst; i <= n; i += 2)
				sum[i - 1] += n + 1 - i;
		}
		lst = n;
		for(int i = n; i >= 1; i--) {
			if(lst == i && c[i] == 'R') {
				lst--;
				continue;
			}
			if(i != lst && c[i] == c[i + 1]) {
				for(int j = lst; j > i; j -= 2)
					sum[j] += j - i;
				if(c[i] == 'L')
					lst = i;
				else
					lst = i - 1;
			}
		}
		if(lst != 0) {
			for(int i = lst; i >= 1; i -= 2)
				sum[i] += i;
		}
		for(int i = 0; i <= n; i++)
			cout << sum[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}