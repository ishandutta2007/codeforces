#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int zb = 0,ob = 1023;
	char o;
	int d;
	for(int j = 0;j<n;j++){
		cin >> o >> d;
		if(o=='&')zb=(zb&d),ob=(ob&d);
		if(o=='|')zb=(zb|d),ob=(ob|d);
		if(o=='^')zb=(zb^d),ob=(ob^d);
	}
	cout << 2 << endl;
	cout << "& " << (zb^ob) << endl;
	cout << "^ " << zb << endl;
	return 0;
}