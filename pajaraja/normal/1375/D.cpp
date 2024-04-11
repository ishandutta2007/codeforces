#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int a[MAXN],p[MAXN],n;
int ndmx()
{
	for(int i=0;i<n;i++) p[i]=a[i];
	sort(p,p+n);
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(p[i]==t) t++;
		if(p[i]>t) return t;
	}
	return t;
}
bool gas()
{
	for(int i=1;i<n;i++) if(a[i]<a[i-1]) return false;
	return true;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int br=0;
		vector<int> v;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		while(!gas())
		{
			br++;
			int t=ndmx();
			if(t!=n && a[t]!=t) {a[t]=t; v.push_back(t); continue;}
			int pl=0,nd=0;
			for(int i=0;i<n;i++) if(a[i]!=i) {pl=i; break;}
			for(int i=0;i<n;i++) if(a[i]==pl) {nd=i; break;}
			v.push_back(nd);
			a[nd]=t;
		}
		printf("%d\n",br);
		for(int i=0;i<br;i++) printf("%d ",v[i]+1);
		printf("\n");
	}
}