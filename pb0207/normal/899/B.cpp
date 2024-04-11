#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+1e3+7;

int g[N],n;

int b[]={31,28,31,30,31,30,31,31,30,31,30,31};

int c[]={31,29,31,30,31,30,31,31,30,31,30,31};

/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n%4==0)
	{
		cout<<0<<endl;
		cout<<n/2<<" ";
		for(int i=1;i<n/2;i+=2)
			cout<<i<<" "<<n-i+1<<" ";
	}
	if(n%4==2)
	{
		cout<<1<<endl;
		cout<<n/2<<" ";
		for(int i=1;i<n/2;i+=2)
			cout<<i<<" "<<n-i+1<<" ";
		cout<<n/2;
	}
	if(n%4==1)
	{
		cout<<n/2+1<<endl;
		cout<<n/2+1<<" ";
		for(int i=1;i<n/2;i+=2)
			cout<<i<<" "<<n-i+1<<" ";
		cout<<n/2+1;
	}
	if(n%4==3)
	{
		cout<<n/2-1<<endl;
		cout<<n/2+1<<" ";
		for(int i=1;i<n/2;i+=2)
			cout<<i<<" "<<n-i+1<<" ";
		cout<<n/2<<" "<<n/2+1;
	}
}
*/

bool solve(int *a,int *b,int *c)
{
	static int q[N];q[0]=0;
	for(int i=0;i<12;++i)
		q[++q[0]]=a[i];
	for(int i=0;i<12;++i)
		q[++q[0]]=b[i];
	for(int i=0;i<12;++i)
		q[++q[0]]=c[i];
	for(int i=0;i<36-n+1;++i)
	{
		bool flag=1;
		int k=i;
		for(int j=1;j<=n;++j)
			if(q[k++]!=g[j])
				flag=0;
		if(flag)
		{
			puts("YES");
			exit(0);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&g[i]);
	solve(b,b,b);
	solve(c,b,b);
	solve(b,c,b);
	solve(b,b,c);
	puts("NO");
}