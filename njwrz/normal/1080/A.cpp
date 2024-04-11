#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a=n*2,b=n*5,c=n*8;
	if(a%m!=0)a=a/m+1;else a/=m;
	if(b%m!=0)b=b/m+1;else b/=m;
	if(c%m!=0)c=c/m+1;else c/=m;
	cout<<a+b+c;
	return 0;
}