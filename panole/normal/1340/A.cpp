#include<bits/stdc++.h>
using namespace std;

bool bo;
int n,T,p[100010],po[100010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n),bo=1;
		for (int i=1; i<=n; i++) scanf("%d",&p[i]),po[p[i]]=i;
		int nw=1,x,la=n;
		while (la)
		{
			x=po[nw];
			int La=x-1;
			while (x<la) 
			{
				if (p[x+1]!=p[x]+1) {bo=0; break;}
				x++,nw++;
			}
			if (!bo) break;
			la=La,nw++;
		}
		puts(bo?"Yes":"No");
	}
	return 0;
}