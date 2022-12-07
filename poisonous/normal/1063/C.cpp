#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main()
{
	int n;
	cin>>n;
	cout<<0<<' '<<1<<endl;
	fflush(stdout);
	scanf("%s",a);
	int l=0,r=1<<29;
	n--;
	for(int i=1;i<=n;i++)
	{
		int mid=(l+r)>>1;
		cout<<mid<<' '<<1<<endl;
		fflush(stdout);
		scanf("%s",b);
		if(b[0]==a[0])
			l=mid;
		else
			r=mid;
	}
	cout<<l<<' '<<0<<' '<<r<<' '<<2<<endl;
	fflush(stdout);
}