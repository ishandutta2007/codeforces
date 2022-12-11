#include <bits/stdc++.h>

using namespace std;

bool is(int k){
	if(k==1)return true;
	int l = 2;
	for(int i = 0;i<10;i++){
		if((l-1)*(l/2)==k)
			return true;	
		l*=2;
	}		
	return false;
}	
	
int main(){
	int n;
	cin >> n;	
	for(int i = n;i>=1;i--){
		if(n%i!=0)continue;
		if(is(i)){
			cout << i << "\n";	
			exit(0);
		}
	}
	return 0;
}