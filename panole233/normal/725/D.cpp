#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

multiset<long long> asd;

struct node{long long a,c;}y[300001];

long long n,s,x,sol=0,lalala=10000000000000;

bool cmp(node a,node b){return a.a>b.a;}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&s,&x);
	for (long long i=1; i<n; i++) 
		scanf("%I64d%I64d",&y[i].a,&x),y[i].c=x-y[i].a+1;
	sort(y+1,y+n,cmp);
	long long i=1;
	while (y[i].a>s&&i<n) asd.insert(y[i++].c);
	lalala=min(lalala,i-sol);
	while (s)
	{
		if (asd.empty()) break;
		x=*asd.begin();
		if (s>=x) s-=x,asd.erase(asd.begin()),sol++; else break;
		while (y[i].a>s&&i<n) asd.insert(y[i++].c);
		lalala=min(lalala,i-sol);
		if (asd.empty()) break;
	}
	printf("%I64d",lalala);
	return 0;
}