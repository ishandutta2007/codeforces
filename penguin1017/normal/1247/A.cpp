#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
int main()
{
	int a,b,da,db;
	cin>>da>>db;
	if(da==9&&db==1){
		printf("9 10");
		return 0;
	}
	if(da+1==db){
		cout<<da<<' '<<db;
		return 0;
	}
	if(da==db){
		cout<<da<<0<<' '<<db<<1;
		return 0; 
	}
	cout<<-1;
}