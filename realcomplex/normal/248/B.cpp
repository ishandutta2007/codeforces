#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n<3)cout << -1 << endl;
	else if(n==3)cout << 210 << endl;
	else{
		int mods[]={170,20,200,110,50,80};
		if(n%6==5||n%6==4||n%6==1){
			cout << 10;
			for(int j = 2;j<n-2;j++)cout << 0;
			cout << mods[n%6];
			cout << endl;
		}
		else{
			cout << 10;
			for(int j = 2;j<n-3;j++)cout << 0;
			cout << mods[n%6];
			cout << endl;
		}
	}
	return 0;
}