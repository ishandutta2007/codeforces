
#include <bits/stdc++.h>
 
typedef long long ll;
ll _m = 1000000007;
 
using namespace std;
 
ll prec[100010];

int main(){
	int n, m;
	cin >> n >> m;
	// O(n + m)
	
	prec[0] = 1; 
	prec[1] = 2;
	for(int i = 2; i < 100000; i++){
		prec[i] = prec[i - 1] + prec[i - 2];
		prec[i] %= _m;
	}
	if(n == 1 || m == 1){
		cout << prec[n - 1] * prec[m - 1] * 2 % _m;
		return 0;
	}else{
		cout << ((prec[n - 1] + prec[m - 1]) * 2 - 2) % _m;
	}
	return 0;
}