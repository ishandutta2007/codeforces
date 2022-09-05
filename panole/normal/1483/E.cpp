#include<bits/stdc++.h>
using namespace std;

int T;
long long l,r,mid,nw,lim;

bool ask(long long x)
{
	if (x>100000000000000ll) return 0;
	printf("? %lld\n",x),fflush(stdout);
	char s[20];
	scanf("%s",s);
	if (s[0]=='L') nw+=x; else nw-=x;
	return s[0]=='L';
}

/*int cnt=0;
bool ask(long long x)
{
	if (x>100000000000000ll) return 0;
	cnt++;
	printf("? %lld\n",x),fflush(stdout);
	if (x<=52586926206212ll) nw+=x; else nw-=x;
	return x<=52586926206212ll;
}*/

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		nw=1,lim=1;
		while (ask(lim)) lim<<=1;
		l=lim/2,r=min(100000000000000ll,lim-1);
		int c=0;
		while (r>l)
		{
			mid=(l*3+r*(c+1))/(c+4);
			while (nw<mid+1) ask(l);
			if (ask(mid+1)) l=mid+1,c++; else r=mid,c=max(c-1,0);
		}
		//printf("%d\n",cnt);
		printf("! %lld\n",l),fflush(stdout);
	}
	return 0;
}