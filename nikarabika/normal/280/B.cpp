#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 85 - 85 + 1;
int a[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int fi, se;
	int Max = 0;
	for(int i = 30; i >= 0; i--){
		int p;
		for(int j = 0; j < n; j = p){
			p = j + 1;
			int Maxa = 0;
			if(a[j] & (1 << i)){
				while(p < n and (a[p] & (1 << i)) == 0){
					Maxa = max(Maxa, a[p]);
					Max = max(Max, a[j] ^ Maxa);
					p++;
				}
			}
		}
		for(int j = n - 1; j >= 0; j = p){
			p = j - 1;
			int Maxa = 0;
			if(a[j] & (1 << i)){
				while(p >= 0 and (a[p] & (1 << i)) == 0){
					Maxa = max(Maxa, a[p]);
					Max = max(Max, a[j] ^ Maxa);
					p--;
				}
			}
		}
		if(Max != 0)
			break;
	}
	cout << Max << endl;
	return 0;
}