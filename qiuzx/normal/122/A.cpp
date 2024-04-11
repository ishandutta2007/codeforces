#include <bits/stdc++.h>
using namespace std;
int con(int x,int y,int n)
{
	int k;
	while(n!=0)
	{
		k=n%10;
		if(k!=x&&k!=y)
		{
			return 0;
		}
	}
	return 1;
}
int main(){
	int lv[15]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	int n,i;
	cin>>n;
	for(i=0;i<14;i++)
	{
		if(n%lv[i]==0)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}