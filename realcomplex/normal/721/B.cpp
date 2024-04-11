#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main(){
	int n,k;
	cin >> n >> k;
	string a;
	for(int j = 0;j<n;j++){
		cin >> a;
		cnt[int(a.size())]++;
	}
	cin >> a;
	int v = a.size();
	int m = 0;
	for(int j = 0;j<v;j++)m+=cnt[j];
	cout << ((m/k)*5)+1+m << " ";
	m += cnt[v];
	m--;
	cout << ((m/k)*5)+m+1 << "\n";
	return 0;
}