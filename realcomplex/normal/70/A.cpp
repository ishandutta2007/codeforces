#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6+3;

int k(int a,int p){
	int rez = 1;
	for(int j = 0;j<p;j++)rez=(rez*a)%mod;
	return rez;
}

int main(){
	int n;
	cin >> n;
	if(n==0)cout << 1;
	else cout << k(3,n-1);
	cout << endl;
	return 0;
}