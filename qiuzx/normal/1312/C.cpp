#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
/*
Before Submitting, check:(Delete them before submitting)
*int or long long
*the range of every array(will it get an RE and is it bg enough?)
*special cases(0,1...)
*/
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll t,n,k,a;
bool tp[1100][110],fd;
int main(){
	ll i,j;
	t=rint();
	while(t--)
	{
		memset(tp,false,sizeof(tp));
		fd=true;
		n=rint();
		k=rint();
		for(i=0;i<n;i++)
		{
			j=0;
			a=rint();
			while(a!=0)
			{
				if(tp[j][a%k]&&a%k!=0)
				{
					fd=false;
					break;
				}
				if(a%k>1)
				{
					fd=false;
					break;
				}
				tp[j][a%k]=true;
				a/=k;
				j++;
			}
		}
		if(fd)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}