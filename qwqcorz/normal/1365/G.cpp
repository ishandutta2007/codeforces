#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll ask(vector<int>&a)
{
	printf("? %d ",(int)a.size());
	for (int i:a) print(i,' ');
	cout<<endl;
	return read();
}
ll OR[13],ans[N];
int id[N];
signed main()
{
	int n=read();
	for (int i=1,j=0;i<=n;i++)
	{
		while (__builtin_popcount(++j)!=6);
		id[i]=j;
	}
	for (int j=0;j<13;j++)
	{
		vector<int>a;
		for (int i=1;i<=n;i++) if (id[i]>>j&1) a.push_back(i);
		if (a.size()) OR[j]=ask(a);
	}
	for (int i=1;i<=n;i++)
	for (int j=0;j<13;j++)
	if (~id[i]>>j&1) ans[i]|=OR[j];
	printf("! ");
	for (int i=1;i<=n;i++) print(ans[i],' ');
	cout<<endl;
	
	return 0;
}