#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	string a; getline(cin, a);

	if(a[a.size() - 1] == 'k'){
		++a[0];
		if(a[0] == '6' || a[0] == '7') cout << 53;
		else cout << 52;	
	}
	else{
		int days = 0, i = 0;
		while(a[i] >= '0' && a[i] <= '9'){
			days = days * 10 + a[i] - '0';
			++i;
		}

		if(days <= 29){
			cout << 12;
		}
		else{
			if(days == 30) cout << 11;
			else cout << 7;
		}
	}
}