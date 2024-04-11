#include<algorithm>
#include<iostream>
#include<cstring>
#include<string> 
#include<cstdio>
#include<cmath>
#define LL long long
#define M 
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
string a;
int n,m,t1,t2,l,r,mid,rev;
int main(){
	cin>>n,l=0,r=1000000000;
	if(n==1){cout<<"1 1"<<endl;cin>>a;cout<<"2 0 2 2"<<endl;return 0;}
	n--,cout<<"0 1"<<endl,cin>>a;
	if(a[0]=='b') rev=1;
	while(n--){
		mid=((l+r)>>1);
		cout<<mid<<" 1"<<endl;
		cin>>a;
		if((a[0]=='b')^rev^1) l=mid;
		else r=mid;
	}
	cout<<l<<" 2 "<<r<<" 0"<<endl;
	return 0;
}