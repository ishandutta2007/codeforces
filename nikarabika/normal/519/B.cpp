#include <bits/stdc++.h>

using namespace std;

map<int, int> m, w;

int main(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		cin >> b[i];
		w[b[i]]++;
	}
	for(int i = 2; i < n; i++){
		int x;
		cin >> x;
		m[x]++;
	}
	int ans1=0, ans2=0;
	for(int i = 1; i < n; i++){
		if(m[b[i]] == 0)
			ans2 = b[i];
		else
			m[b[i]]--;
	}
	for(int i = 0; i < n; i++){
		if(w[a[i]] == 0)
			ans1 = a[i];
		else
			w[a[i]]--;
	}
	cout << ans1 << endl << ans2 << endl;
}