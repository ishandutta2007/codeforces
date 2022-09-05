#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;
int n,x[1010],y[1010];
vector<int> v;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&x[i],&y[i]);
	while (1)
	{
		for (int i=2; i<=n; i++)
			if (((inf+x[i]+y[i])&1)!=((inf+x[1]+y[1])&1))
			{
				v.clear();
				for (int i=1; i<=n; i++)
					if (((inf+x[i]+y[i])&1)==((inf+x[1]+y[1])&1)) v.push_back(i);
				printf("%d\n",(int)v.size());
				for (int i=0,sz=v.size(); i<sz; i++) printf("%d ",v[i]);
				return puts(""),0;
			}
		for (int i=2; i<=n; i++)
			if (((inf+x[i])&1)!=((inf+x[1])&1))
			{
				v.clear();
				for (int i=1; i<=n; i++)
					if (((inf+x[i])&1)==((inf+x[1])&1)) v.push_back(i);
				printf("%d\n",(int)v.size());
				for (int i=0,sz=v.size(); i<sz; i++) printf("%d ",v[i]);
				return puts(""),0;
			}
		for (int i=1; i<=n; i++)
		{
			if ((inf+x[i])&1) x[i]++;
			if ((inf+y[i])&1) y[i]++;
			x[i]>>=1,y[i]>>=1;
		}
	}
	return 0;
}