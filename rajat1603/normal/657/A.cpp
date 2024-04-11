#include "bits/stdc++.h"
using namespace std;
int n , d , h;
int lst;
int main(){
	cin >> n >> d >> h;
	if(d > h + h){
		cout << "-1\n";
		return 0;
	}
	if(d == h){
		if(d == 1){
			if(n == 2){
				cout << "1 2\n";
				return 0;
			}
			cout << "-1\n";
			return 0;
		}
		for(int i = 2 ; i <= 1 + h ; ++i){
			cout << i << " " << i - 1 << "\n";
		}
		for(int i = h + 2 ; i <= n ; ++i){
			cout << "2 " << i << "\n";
		}
		return 0;
	}
	for(int i = 1 ; i <= h ; ++i){
		cout << i << " " << i + 1 << "\n";
		--d;
	}
	lst = 1;
	for(int i = h + 2 ; i <= h + d + 1 ; ++i){
		cout << lst << " " << i << "\n";
		lst = i;
	}
	for(int i = lst + 1 ; i <= n ; ++i){
		cout << "1 " << i << "\n";
	}
}