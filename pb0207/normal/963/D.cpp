#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,sd=1313131,P=1e9+7;

ll hs[N],mi[N];

ll geth(int l,int r)
{
	return (hs[r]-hs[l-1]*mi[r-l+1]%P+P)%P;
}

struct Query{
	ll h;
	int len,id,k;
}qt;

bool operator <(Query a,Query b)
{
	return a.h<b.h;
}

vector<Query>q[N];

vector<int>pos[N];

char s[N],t[N];

int n,len,ans[N];

int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	int tot=len;
	mi[0]=1;
	for(int i=1;i<=len;i++)
		hs[i]=(hs[i-1]*sd%P+s[i])%P,mi[i]=mi[i-1]*sd%P;
	scanf("%d",&n);
	int totlen=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&qt.k);
		scanf("%s",t+1);
		len=strlen(t+1);
		qt.h=0;
		qt.len=len;
		totlen+=len;
		qt.id=i;
		for(int j=1;j<=len;j++)
			qt.h=(qt.h*sd%P+t[j])%P;
		q[len].push_back(qt);
		ans[i]=0x7fffffff;
	}
	assert(totlen<=100000);
	for(int i=1;i<=tot;i++)
		sort(q[i].begin(),q[i].end()); 
	for(int i=1;i<=tot;i++)
		if(q[i].size())
			for(int j=1;j<=tot-i+1;j++)
			{
				ll ht=geth(j,j+i-1);
				Query tmp;
				tmp.h=ht;
				int x=lower_bound(q[i].begin(),q[i].end(),tmp)-q[i].begin();
				if(x>=q[i].size())
					continue;
				if(ht!=q[i][x].h)
				 	continue;
				int num=q[i][x].k;
				x=q[i][x].id;
				pos[x].push_back(j);
				if((int)pos[x].size()>=num)
					ans[x]=min(ans[x],pos[x][pos[x].size()-1]+i-1-pos[x][pos[x].size()-1-num+1]+1);
			}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]==0x7fffffff?-1:ans[i]);
}