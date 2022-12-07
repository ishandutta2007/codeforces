#include <bits/stdc++.h>

using namespace std;

int cnt[11];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
			freopen("1.out", "w", stdout);
	#endif

	string a[] = { "0000", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};

	for(int i = 0; i < 10; ++i){
		cout << a[i] << endl;
		fflush(stdout);
		int u, v; 
		scanf("%d%d", &u, &v);
		
		cnt[i] = u;


		if(u == 4) return 0; 
	}

	string s = "";

	for(int i = 0; i <= 9; ++i){
	//	cout << cnt[i] << endl;

		for(int j = 1; j <= cnt[i]; ++j){
			s += char(i + '0');
		}	
	}

	cout << s << endl;

	do{
		cout << s << endl;
		fflush(stdout);

		int u, v;
		scanf("%d%d", &u, &v);

		if(u == 4) break;
	} while(next_permutation(s.begin(), s.end()));
}