#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,k,tot,x;

int main()
{
	cin>>n>>k;
	tot=(n-1)/k;
	if((n-1)%k!=0)
		tot++;
	if((n-1)%k==1)
		cout<<tot+tot-1<<endl;
	else
		cout<<2*tot<<endl;
	for(int i=2;i<=k;i++)
        printf("%d %d\n",1,i);
    for(int i=k+1;i<=n;i++)
    {
        printf("%d %d\n",i-k,i);
    }
}