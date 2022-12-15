#include<bits/stdc++.h>
using namespace std;

vector<int> b[1010];
int n,a[400010],ans;
map<int,int> ma;
map<int,int>::iterator it;
pair<int,int> p[400010];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),ma[a[i]]++;
	int pn=0,nw,nww=0;
	for (it=ma.begin(); it!=ma.end(); it++)
		p[++pn]=make_pair((*it).second,(*it).first);
	nw=pn;
	sort(p+1,p+1+pn),reverse(p+1,p+1+pn);
	int ma=0,maa;
	for (int i=1; i<=n; i++)
	{
		nww+=nw;
		if (nww<i*i) break;
		if (i*(nww/i)>ma) ma=i*(nww/i),maa=i;
		while (nw&&p[nw].first==i) nw--;
	}
	ans=maa,nw=0;
	for (int i=1; i<=pn; i++)
		p[i]=make_pair(min(p[i].first,ans),p[i].second),nw+=p[i].first;
	nw/=ans;
	for (int i=1; i<=ans; i++) b[i].resize(nw);
	int pp=1;
	for (int i=0; i<nw; i++)
		for (int j=1,x=i; j<=ans; j++,x=(x+1)%nw)
		{
			b[j][x]=p[pp].second,p[pp].first--;
			if (!p[pp].first) pp++;
		}
	printf("%d\n%d %d\n",nw*ans,ans,nw);
	for (int i=1; i<=ans; i++,puts(""))
		for (int j=0; j<nw; j++) printf("%d ",b[i][j]);
	return 0;
}