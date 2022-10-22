#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

struct node{
	int a,t;
	int id;
}o[N];

int n,T;

int a[N],t[N];

vector<int>w;

bool chk(int m)
{
	w.clear();
	for(int i=1;i<=n;i++)
		if(o[i].a>=m)
			w.push_back(o[i].t);
	sort(w.begin(),w.end());
	int tot=0,tt=T;
	for(int i=0;i<w.size();i++)
		if(tt>=w[i])
			tt-=w[i],tot++;
		else
			break;
	return tot>=m;
}

bool cmp(node a,node b)
{
	return a.t<b.t;
}

vector<node>f;

void OT(int an)
{
	printf("%d\n",an);
	printf("%d\n",an);
	for(int i=1;i<=n;i++)
		if(o[i].a>=an)
			f.push_back(o[i]);
	sort(f.begin(),f.end(),cmp);
	for(int i=0;i<an;i++)
		printf("%d ",f[i].id);
}

int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&o[i].a,&o[i].t),o[i].id=i;
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(chk(mid))
			l=mid;
		else
			r=mid;
	}
	OT(l);
}