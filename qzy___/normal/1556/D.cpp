#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+1;
int n,k,A,B,C,D,E,F,a,b,c,d,e,f,p,s[N];
int H(int x,int y)
{
	cout<<"and "<<x<<' '<<y<<'\n';
	fflush(stdout);
	cin>>p;
	return p;
}
int O(int x,int y)
{
	cout<<"or "<<x<<' '<<y<<'\n';
	fflush(stdout);
	cin>>p;
	return p;
}
signed main()
{
	cin>>n>>k;
	A=H(1,2),B=H(2,3),C=H(3,1),D=O(1,2),E=O(2,3),F=O(3,1);
	for(int i=0;i<31;i++)
	{
		a=A>>i&1,b=B>>i&1,c=C>>i&1,d=D>>i&1,e=E>>i&1,f=F>>i&1;
		if(a+b+c==3)
			s[1]+=1<<i,s[2]+=1<<i,s[3]+=1<<i;
		if(d+e+f==0)
			continue;
		if(a+b+c==0&&d==0)
			s[3]+=1<<i;
		if(a+b+c==0&&e==0)
			s[1]+=1<<i;
		if(a+b+c==0&&f==0)
			s[2]+=1<<i;
		if(a+b+c==1&&a)
			s[1]+=1<<i,s[2]+=1<<i;
		if(a+b+c==1&&b)
			s[2]+=1<<i,s[3]+=1<<i;
		if(a+b+c==1&&c)
			s[3]+=1<<i,s[1]+=1<<i;
	}
	for(int i=4;i<=n;i++)
	{
		A=H(1,i),B=O(1,i);
		for(int j=0;j<31;j++)
		{
			a=A>>j&1,b=B>>j&1;
			if(s[1]>>j&1)
				s[i]+=a<<j;
			else
				s[i]+=b<<j;
		}
	}
	sort(s+1,s+n+1);
	cout<<"finish "<<s[k];
	fflush(stdout);
	return 0;
}