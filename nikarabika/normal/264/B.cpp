#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 10;
int a[maxn], l[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		int Max = 0;
		int x = a[i];
		vector<int> v;
		for(int div = 2; div * div <= x; div++) if(x % div == 0){
			v.PB(div);
			if(l[div] > Max)
				Max = l[div];
			while(x % div == 0)
				x /= div;
		}
		if(x > 1)
			v.PB(x), Max = max(Max, l[x]);
		for(int j = 0; j < v.size(); j++)
			l[v[j]] = Max + 1;
	}
	int ans = 0;
	for(int i = 0; i <= 1e5; i++)
		if(l[i] > ans)
			ans = l[i];
	cout << ans << endl;
	return 0;
}