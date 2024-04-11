#include<iostream>

using namespace std;

int n,m,cnt=0,b=1;

int main(){
	cin>>n>>m;
	cnt=1<<30;
	while(cnt>=n){
		b=1,cnt=0;
		for(;b<=m;b<<=1,cnt++);
		cnt--,b>>=1;
		m-=b;
	}
	if(cnt>=n)
		cout<<m<<endl;
	else
		cout<<m+b<<endl;
	return 0;
}