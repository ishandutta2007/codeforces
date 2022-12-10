#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 85 - 69;
bool can[maxn];
int a[maxn], is[maxn], isnt[maxn];
int n, m, sumisnt, c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > 0) is[a[i]]++;
		else isnt[-a[i]]++, sumisnt++;
	}
	for(int i = 1; i <= n; i++)
		if(sumisnt - isnt[i] + is[i] == m)
			c += (can[i] = true);
	for(int i = 1; i <= n; i++){
		if(a[i] > 0){
			if(!can[a[i]])
				cout << "Lie\n";
			else if(c > 1)
				cout << "Not defined\n";
			else
				cout << "Truth\n";
		}
		else{
			if(!can[-a[i]])
				cout << "Truth\n";
			else if(c == 1)
				cout << "Lie\n";
			else
				cout << "Not defined\n";
		}
	}
	return 0;
}