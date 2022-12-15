#include<bits/stdc++.h>
using namespace std;

int t[4][11][11][100001],n,q,a[1001],ord,x,len,l,r;
char s[100010],c[20];

int add(int i,int j,int k,int x,int v)
{
	for (; x<=100000; x+=(x&-x)) t[i][j][k][x]+=v;
}

int query(int i,int j,int k,int x)
{
	int ans=0;
	for (; x; x-=(x&-x)) ans+=t[i][j][k][x];
	return ans;
}

int main()
{
	scanf("%s",s),n=strlen(s);
	a['A']=0,a['T']=1,a['C']=2,a['G']=3;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=10; j++) add(a[s[i-1]],j,i%j,(i-1)/j+1,1);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&ord);
		if (ord==1)
		{
			scanf("%d%s",&x,c);
			for (int j=1; j<=10; j++) add(a[s[x-1]],j,x%j,(x-1)/j+1,-1);
			s[x-1]=c[0];
			for (int j=1; j<=10; j++) add(a[s[x-1]],j,x%j,(x-1)/j+1,1);
		} else
		{
			scanf("%d%d%s",&l,&r,c),len=strlen(c);
			int ans=0,nw=r,bef=l-len;
			while (nw%len!=l%len) nw--;
			for (int j=0; j<len; j++,nw++,bef++) 
			{
				if (nw>r) nw-=len;
				if (bef>=l) bef-=len;
				if (nw>=l) ans+=query(a[c[j]],len,nw%len,(nw-1)/len+1)-(bef>0?query(a[c[j]],len,nw%len,(bef-1)/len+1):0);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}