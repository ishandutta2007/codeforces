#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin >> n;
	bool state = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		if(v % 2 == 0){
			cout << v / 2 << endl;
			continue;
		}
		if(v < 0){
			if(state){
				cout << (v - 1) / 2 << endl;
			}else{
				cout << v / 2 << endl;
			}
		}else{
			if(state){
				cout << v / 2 << endl;
			}else{
				cout << (v + 1) / 2 << endl;
			}
		}
		state ^= 1;
	}
	return 0;
}