#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
char a[150];
typedef __int64 ll;
int pb,ps,pc;
int nb,ns,nc,b,s,c;
ll r,ans;
using namespace std;
void erfen(ll left,ll right)
{
	ll b1,c1,s1;
	if(ans!=0)
		return;
	if(left<right)
	{
		ll mid=(left+right+1)/2;
		b1=mid*b-nb;
		c1=mid*c-nc;
		s1=mid*s-ns;
		if(b1<0)
			b1=0;
		if(c1<0)
			c1=0;
		if(s1<0)
			s1=0;
		if(b1*pb+c1*pc+s1*ps<r)
			erfen(mid,right);
		else if(b1*pb+c1*pc+s1*ps>r)
			erfen(left,mid-1);
                else
                {
                    ans=mid;
                    return;
                }
	}
	else
		ans=left;
	return ;
}
int main()
{
	cin>>a;
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='B')
			b++;
		if(a[i]=='S')
			s++;
		if(a[i]=='C')
			c++;
	}
	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	ll right,left=0;
	scanf("%I64d",&r);
	right=nb+ns+nc+r;
	erfen(left,right);
	printf("%I64d\n",ans);
	return 0;
}