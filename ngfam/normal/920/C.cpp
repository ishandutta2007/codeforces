#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n;
int a[N];
char r[N];
int mn[N];

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	mn[n] = a[n];
	for(int i = n - 1; i >= 1; --i){
		mn[i] = min(mn[i + 1], a[i]);
	}

	scanf("%s", r + 1);

	int mx = 0;
	for(int i = 1; i <= n; ++i){
		mx = max(mx, a[i]);

		if(r[i] == '0'){
			if(mx > mn[i + 1]){
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";

	return 0;
}