#include <bits/stdc++.h>
using namespace std;
int main(){
	int l,b,year=0;
	cin>>l>>b;
	while(l<=b)
	{
		year++;
		l*=3;
		b*=2;
	}
	cout<<year<<endl;
	return 0;
}