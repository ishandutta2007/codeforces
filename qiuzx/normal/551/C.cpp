//QwQ
//copied from an unknown code
#include<bits/stdc++.h>
using namespace std;

int n, m;
long long init[100100];
long long a[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> init[i];
	long long lb = 0, ub = 1e18;
	while(lb <= ub){
		long long mid = (lb + ub) >> 1;
		long long nowm = m, nowrem = 0;
		long long hastime = mid;
		for(int i = 0; i < n; i++){
			hastime--;
			if(nowrem)
				nowrem--;
			a[i] = init[i];
			if(a[i]){
				if(hastime <= 0){
					nowm = -1;
					break;
				}
				long long rem = min(nowrem, a[i]);
				nowrem -= rem, a[i] -= rem;
				long long need = a[i] / hastime;
				a[i] -= hastime * need, nowm -= need;
				if(a[i])
					nowm--, nowrem = hastime - a[i];
			}
		}
		if(nowm >= 0)
			ub = mid - 1;
		else
			lb = mid + 1;
	}
	cout << lb << endl;
	return 0;
}