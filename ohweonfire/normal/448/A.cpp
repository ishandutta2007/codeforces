#include <iostream>
#include <stdio.h>
using namespace std;
int x,y,z;
int n1,n2,n3;
int n;
int main(){
	cin>>n1>>n2>>n3>>x>>y>>z>>n;
	if((n1+n2+n3+4)/5+(x+y+z+9)/10>n)cout<<"NO";
	else cout<<"YES";
	return 0;
}