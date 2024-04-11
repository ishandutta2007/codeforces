#include<bits/stdc++.h>
using namespace std;

bool bo[1200010];
int n,a[100010],id[1048577],m,k,d[1048577],l,r,q[1048577];
vector<int> v[1048577],E[1048577];

int read()
{
	char s[5]; 
	int ans=0;
	scanf("%s",s);
	for (int i=0; i<k; i++) ans|=((s[i]=='_'?26:s[i]-'a')<<(i*5));
	return ans;
}

void Getedge(int nw,int y,int x)
{
	if (x==k) {v[y].push_back(nw); return;}
	if (((y>>(x*5))&31)==26) {for (int i=0; i<=26; i++) Getedge(nw|(i<<(x*5)),y,x+1);}
	else Getedge(nw|(((y>>(x*5))&31)<<(x*5)),y,x+1),Getedge(nw|(26<<(x*5)),y,x+1);
}

void getedge(int nw,int x)
{
	if (x==k) 
	{
		Getedge(0,nw,0);
		return;
	}
	for (int i=0; i<=26; i++) getedge(nw|(i<<(x*5)),x+1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	getedge(0,0);
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=m; i++)
	{
		int x=read(),y; scanf("%d",&y);
		if (id[a[y]]&&id[a[y]]!=y) return puts("NO"),0;
		bool bo=0; id[a[y]]=y,y=a[y];
		for (int j=0,sz=v[x].size(); j<sz; j++)
			if (v[x][j]==y) bo=1; else d[v[x][j]]++,E[y].push_back(v[x][j]);
		if (!bo) return puts("NO"),0;
	}
	l=1,r=0;
	for (int i=0; i<1048576; i++) if (!d[i]) q[++r]=i;
	while (l<=r)
	{
		int x=q[l++];
		for (int i=0,sz=E[x].size(); i<sz; i++)
			if (!(--d[E[x][i]])) q[++r]=E[x][i];
	}
	if (r!=1048576) return puts("NO"),0;
	puts("YES");
	for (int i=1; i<=1048576; i++) if (id[q[i]]) printf("%d ",id[q[i]]),bo[id[q[i]]]=1;
	for (int i=1; i<=n; i++) if (!bo[i]) printf("%d ",i);puts("");
	return 0;
}