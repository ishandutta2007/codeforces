#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int p[N];
int work(int n,vector<int>a)
{
	print(a.size(),' ');
	for (int i:a) print(i,' ');
	cout<<endl;
	int ret=0;
	for (int i:a) ret+=p[i]=1;
	int x=read();
	for (int i=0;i<(int)a.size();i++)
	{
		if (p[x]) p[x]=0,ret--;
		x++;
		if (x>n) x=1;
	}
	return ret;
}

signed main()
{
	int n=read(),k=sqrt(n),mx=n-k-(n-1)/k,now=0;
	while (now<mx)
	{
		vector<int>a;
		for (int i=1;i<=n;i++) if (!p[i]&&i%k!=1)
		{
			a.push_back(i);
			if ((int)a.size()==k) break;
		}
		now+=work(n,a);
	}
	puts("0");
	
	return 0;
}