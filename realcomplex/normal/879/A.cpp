#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int l = 0;
	int st,v;
	for(int j = 0;j<n;j++){
		cin >> st >> v;
		if(st>l)l=st;
		else{
			while(st<=l)st+=v;
			l = st;	
		}
	}
	cout << l << endl;
	return 0;
}