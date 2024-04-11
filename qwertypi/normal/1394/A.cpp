#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 100010
#define int long long
int A[MAXN];
 
int prec[MAXN];
int32_t main(){
	int n, d, m;
	cin >> n >> d >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	sort(A, A + n);
	for(int i = 0; i < n; i++){
		prec[i + 1] = prec[i] + A[i];
	}
	int sm = 0;
	for(int i = 0; i < n; i++){
		if(A[i] <= m) sm++;
	}
	long long ans = 0;
	for(int i = 0; i <= n - sm; i++){
		int bday = max(0LL, i - 1) * d;
		int lday = min(n - bday - i, sm);
		
		if(lday < 0){
			continue;
		}else{
			int res = prec[n] - prec[n - i] + prec[sm] - prec[sm - lday];
			ans = max(ans, res);
		}
	}
	cout << ans << endl;
}