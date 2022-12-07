#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	int n; cin >> n;

	for(int i = 1; i <= n; ++i){
		string a; int fr, to;
		cin >> a >> fr >> to;

		if(fr >= 2400 && to > fr){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}