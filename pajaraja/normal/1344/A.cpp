#include <bits/stdc++.h>
using namespace std;
bool vi[1000007];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		bool fas=false;
		scanf("%d",&n);
		fill(vi,vi+n+5,false);
		for(int i=0;i<n;i++)
		{
			int tmp,val;
			scanf("%d",&tmp);
			tmp+=i;
			if(tmp>0) val=tmp%n;
			else
			{
				val=n-(-tmp)%n;
				if(val==n) val=0;
			}
			if(vi[val]) fas=true;
			vi[val]=true;
		}
		if(fas) printf("NO\n");
		else printf("YES\n");
	}
}