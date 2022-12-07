#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif	

	int a, b;
	cin >> a >> b;

	vector < int > ans;

	while(b > a){
		ans.push_back(b);

		if(b % 10 == 1) b /= 10;
		else{
			if(b % 2 == 0) b /= 2;
			else{
				break;
			}
		}
	}

	if(b != a) puts("NO");
	else{
		puts("YES");
		printf("%d\n", int(ans.size()) + 1);
		printf("%d ", a);

		for(int i = ans.size() - 1; i >= 0; --i){
			  printf("%d ", ans[i]);
		}
	}
}