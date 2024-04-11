#include<bits/stdc++.h>
using namespace std;

int n,a[300010],b[300010],ansn,ans[2000010][3],cnt,id[300010],q1[300010],q2[300010],l1,l2,nw1,nw2;
long long sa,sb;

bool cmp(int x,int y) {return a[x]<a[y];}

int main()
{
	scanf("%d",&n),sa=sb=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),sa+=a[i],id[i]=i;
	for (int i=1; i<=n; i++) scanf("%d",&b[i]),sb+=b[i];
	if (sa!=sb) return puts("NO"),0;
	sort(id+1,id+1+n,cmp);
	sort(b+1,b+1+n),l1=l2=0;
	for (int i=1; i<=n; i++)
		if (a[id[i]]>b[i]) q1[++l1]=i; else
		if (a[id[i]]<b[i]) q2[++l2]=i;
	nw1=nw2=1,ansn=0;
	while (nw1<=l1&&nw2<=l2)
	{
		if (a[id[q1[nw1]]]<=a[id[q2[nw2]]]) return puts("NO"),0;
		int d=min(a[id[q1[nw1]]]-b[q1[nw1]],b[q2[nw2]]-a[id[q2[nw2]]]);
		ans[++ansn][0]=id[q2[nw2]],ans[ansn][1]=id[q1[nw1]],ans[ansn][2]=d;
		a[id[q1[nw1]]]-=d,a[id[q2[nw2]]]+=d;
		if (a[id[q1[nw1]]]==b[q1[nw1]]) nw1++;
		if (a[id[q2[nw2]]]==b[q2[nw2]]) nw2++;
	}
	puts("YES");
	printf("%d\n",ansn);
	for (int i=1; i<=ansn; i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}