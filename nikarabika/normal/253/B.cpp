#include <bits/stdc++.h>

#define cin fin
#define cout fout

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int p = 0, ans = 1e9;
	for(int i = 0; i < n; i++){
		while(p < n and a[p] <= a[i] * 2)
			p++;
		if(i + n - p < ans)
			ans = i + n - p;
	}
	cout << ans << endl;
	return 0;
}