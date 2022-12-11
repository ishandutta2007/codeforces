#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a;
	cin >> n >> a;
	if(a%2==0){
		int l = n/2;
		int v = a/2;
		cout << (l-v)+1;
	}
	else{
		cout << (a/2)+1;
	}
	cout << endl;
	return 0;
}