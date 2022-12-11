#include <bits/stdc++.h>

using namespace std;

bool can[123];

int main(){
	can[0] = true;
	for(int i = 0;i<=100;i++){
	   if(!can[i])continue;
	   can[i+3] = true;
	   can[i+7] = true;
	}
	int q;
	scanf("%i",&q);
	int l;
	for(int i = 0;i<q;i++){
		scanf("%i",&l);
		cout << ((can[l]) ? "YES" : "NO") << "\n";
	}
	return 0;
}