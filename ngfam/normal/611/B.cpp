#include <bits/stdc++.h>

using namespace std;

long long a, b;

typedef long long llint;

llint calc(llint u){
	if(u == 0) return 0;
	bitset<65> x(u);
	//cout << x << endl;
	
	int st = x.size() - 2;
	while(x[st] == 0) --st;

//	cout << x[st] << endl;

	//cout << x << endl;
	int ok = 0;

	
	int cnt = st + 1;
//	cout << x << endl << st << " " << x.size() << " " << x[0] << endl;

	for(int i = st; i >= 0; --i){
		ok += (x[i] == 0);
	}


	llint result = 0;
	for(int i = 1; i < cnt; ++i){
		result += i - 1;
	}

	--st;
	while(st >= 0 && x[st] == 1) ++result, --st;

//	cout << result << " " << cnt << endl;

	return result + (ok == 1); 
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	cin >> a >> b;
//	calc(a); return 0;
	cout << calc(b) - calc(a - 1);
//	cout << calc(b - 1);
}