#include<iostream>
#include<cstdio>
using namespace std;
int a[1002019];
int main()
{
	int aq; cin>>aq;
	while(aq--){
		int n; cin>>n; int n1=n;
		a[0]=1; int mx=1,num=0;
		while(n1)n1>>=1,++num; n-=num;
		for(int i=1;i<num;i++)
			a[i]=min(mx,n/(num-i)),mx+=a[i],n-=(num-i)*a[i];
		cout<<num-1<<endl;
		for(int i=1;i<num;i++)cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}