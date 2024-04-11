#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,m;
char a[200005],b[200005];

int main(){
	cin>>n>>m>>(a+1)>>(b+1);
	int l=1,ra=n,rb=m;
	for(;a[l]==b[l]&&l<=n&&l<=m;l++);
	for(;a[ra]==b[rb]&&ra>=1&&rb>=1;ra--,rb--);
	if(l==ra&&a[l]=='*'&&l<=rb+1)
		cout<<"YES"<<endl;
	else if(l==n+1&&ra==0&&n==m)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}