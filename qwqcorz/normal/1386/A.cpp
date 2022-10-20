#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int debug=0;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int C,last=0;
bool ask(int x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	if (debug)
	{
		int ret=abs(x-last)>=C;
		print(ret);
		last=x;
		return ret;
	}
	return read();
}
void answer(int C)
{
	printf("= %lld\n",C);
	fflush(stdout);
}
void work()
{
	int n=read(),l=1,r=n,f=-1,now=n;
	if (debug) C=read();
	vector<int>tmp;
	for (int l=1,r=n;l<r;)
	{
		int mid=(l+r-1)/2;
		tmp.push_back(mid);
		l=mid+1;
	}
	for (int i=(int)tmp.size()-1;i>=0;i--) now+=f*tmp[i],f*=-1;
	ask(now);
	for (l=1,r=n;l<r;f*=-1)
	{
		int mid=(l+r-1)/2;
		if (ask(now+=f*mid)) r=mid;
						else l=mid+1;
	}
	answer(l);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}