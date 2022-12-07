#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int a, b, f, k;

	cin >> a >> b >> f >> k;

	int ans = 0;
	int current = 0, lit = b;

	for(int i = 1; i <= k; ++i){
		if(current == 0){
			if(lit < f){
				puts("-1");
				return 0;
			}
			if(lit < a){
				++ans;
				lit = b - (a - f);
				
				if(lit < 0){
					puts("-1");
					return 0;
				}
			}
			else{
				if(i < k && (lit - a) < (a - f)){
					++ans;
					lit = b - (a - f);
				}
				else{
					lit -= a;
				}
			}
		}
		else{
			if(lit < (a - f)){
				puts("-1");
				return 0;
			}
			if(lit < a){
				++ans;
				lit = b - f;
				if(lit < 0){
					puts("-1");
					return 0;
				} 
			}
			else{
				if(i < k && (lit - a) < f){
					++ans;
					lit = b - f;
				}
				else{
					lit -= a;
				}
			}
		}
		current = 1 - current;
	}

	cout << ans;

	return 0;
}