#include<bits/stdc++.h>
using namespace std;

int n,ymi,yma,xmi,xma,x[101],y[101],cnt0,cnt1,cnt2,cnt3;

int main()
{
	scanf("%d",&n);
	for (int i=1 ;i<=4*n+1; i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=4*n+1; i++) 
	{
		xmi=ymi=100,xma=yma=-100;
		for (int j=1; j<=4*n+1; j++) if (i!=j) xmi=min(xmi,x[j]),xma=max(xma,x[j]),ymi=min(ymi,y[j]),yma=max(yma,y[j]);
		bool bo=1;
		cnt0=cnt1=cnt2=cnt3=0;
		for (int j=1; j<=4*n+1; j++) if (i!=j&&x[j]!=xmi&&x[j]!=xma&&ymi!=y[j]&&yma!=y[j]) bo=0; else
		{
			if (i!=j)
			{
				if (x[j]==xmi) cnt0++;
				if (x[j]==xma) cnt1++;
				if (y[j]==ymi) cnt2++;
				if (y[j]==yma) cnt3++;
			}
		}
		if (!bo||cnt0<n||cnt1<n||cnt2<n||cnt3<n) continue;
		return printf("%d %d\n",x[i],y[i]),0;
	}
	return 0;
}