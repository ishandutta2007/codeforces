#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	if(n>a*b){
		cout << -1;
		exit(0);
	}
	int l = 1,r = 2;
	for(int i = 0;i<a;i++){
		for(int j = 0;j<b;j++){
			if(i%2==j%2){
				if(l>n){cout << 0 << " ";continue;}
				cout << l << " ";
				l+=2;
			}
			else{
				if(r>n){cout << 0 << " ";continue;}
				cout << r << " ";
				r+=2;
			}
		}
		cout << "\n";
	}
	return 0;
}