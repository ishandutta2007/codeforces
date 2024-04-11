#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,f,o;
	cin>>a>>b;
	f=min(a,b);
	o=max(a,b)-min(a,b);
	o/=2;
	cout<<f<<" "<<o<<endl;
	return 0;
}