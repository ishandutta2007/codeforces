#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,a,on,tn,sn,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		on=tn=sn=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a%3==0)
			{
				sn++;
			}
			else if(a%3==1)
			{
				on++;
			}
			else
			{
				tn++;
			}
		}
		if(on<tn)
		{
			tn-=on;
			cout<<on+tn/3+sn<<endl;
		}
		else
		{
			on-=tn;
			cout<<tn+on/3+sn<<endl;
		}
	}
	return 0;
}