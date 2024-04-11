#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,m,af[5010],ah[5010],pl[5010],pr[5010],s[5010],t[5010],hd[5010],nxt[5010];
vector<int> v[5010];

pair<int,int> operator +(pair<int,int> a,pair<int,int> b)
{
	if (a.first!=b.first) return (a.first<b.first?b:a);
	return make_pair(a.first,(a.second+b.second>=mod?a.second+b.second-mod:a.second+b.second));
}

bool cmp(const int&a,const int&b) {return ah[a]<ah[b];}

int main()
{
	scanf("%d%d",&n,&m),ah[0]=114514;
	for (int i=1; i<=n; i++) scanf("%d",&s[i]),t[s[i]]++,v[i].clear();
	for (int i=1 ;i<=m; i++)
	{
		scanf("%d%d",&af[i],&ah[i]);
		if (t[af[i]]<ah[i]) continue;
		v[af[i]].push_back(i);
	}
	for (int i=1; i<=n; i++) sort(v[i].begin(),v[i].end(),cmp);
	memset(hd,0,sizeof(hd));
	for (int i=n; i; i--) nxt[i]=hd[s[i]],hd[s[i]]=i;
	for (int i=1; i<=n; i++) if (!v[i].empty())
	{
		int x=hd[i];
		for (int j=1; j<ah[v[i][0]]; j++) x=nxt[x];
		pl[v[i][0]]=x;
		for (int j=1,sz=v[i].size(); j<sz; j++)
		{
			for (int k=1; k<=ah[v[i][j]]-ah[v[i][j-1]]; k++) x=nxt[x];
			pl[v[i][j]]=x;
		}
	}
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++) nxt[i]=hd[s[i]],hd[s[i]]=i;
	for (int i=1; i<=n; i++) if (!v[i].empty())
	{
		int x=hd[i];
		for (int j=1; j<ah[v[i][0]]; j++) x=nxt[x];
		pr[v[i][0]]=x;
		for (int j=1,sz=v[i].size(); j<sz; j++)
		{
			for (int k=1; k<=ah[v[i][j]]-ah[v[i][j-1]]; k++) x=nxt[x];
			pr[v[i][j]]=x;
		}
	}
	pair<int,int> ans=make_pair(0,0);
	for (int i=1; i<=n; i++) if (!v[i].empty())
	{
		pair<int,int> nw;
		int lim=pl[v[i][0]];
		if (v[i].size()==1) nw=make_pair(1,1); else
		{
			if (pr[v[i][1]]>lim) 
			{
				nw=make_pair(2,1);
				for (int j=2,sz=v[i].size(); j<sz; j++)
					nw.second+=(pr[v[i][j]]>lim);
			}
			else nw=make_pair(1,1);
		}
		for (int j=1; j<=n; j++) if (i!=j&&!v[j].empty())
		{
			int p1=v[j].size(),p2=v[j].size();
			for (int k=0,sz=v[j].size(); k<sz; k++)
				if (pl[v[j][k]]>lim) {p1=k; break;}
			for (int k=0,sz=v[j].size(); k<sz; k++)
				if (pr[v[j][k]]<lim) {p2=k; break;}
			if (!p1&&!p2) continue;
			if (!p1||!p2||p1==1&&p2==1) nw.first++,nw.second=1ll*nw.second*(p1+p2)%mod;
			else 
			{
				if (p1>p2) swap(p1,p2);
				nw.first+=2,nw.second=1ll*nw.second*(p1*(p2-1))%mod;
			}
		}
		ans=(ans+nw);
		for (int l=1,sz=v[i].size(); l<sz; l++)
		{
			lim=pl[v[i][l]];
			if (lim<pr[v[i][0]]) 
			{
				nw=make_pair(2,1);
				for (int j=1,sz=v[i].size(); j<sz; j++)
					if (j!=l) nw.second+=(pr[v[i][j]]>lim);
			}
			else nw=make_pair(1,1);
			for (int j=1; j<=n; j++) if (i!=j&&!v[j].empty())
			{
				int p1=v[j].size(),p2=v[j].size();
				for (int k=0,sz=v[j].size(); k<sz; k++)
					if (pl[v[j][k]]>lim) {p1=k; break;}
				for (int k=0,sz=v[j].size(); k<sz; k++)
					if (pr[v[j][k]]<lim) {p2=k; break;}
				if (!p1&&!p2) continue;
				if (!p1||!p2||p1==1&&p2==1) nw.first++,nw.second=1ll*nw.second*(p1+p2)%mod;
				else 
				{
					if (p1>p2) swap(p1,p2);
					nw.first+=2,nw.second=1ll*nw.second*(p1*(p2-1))%mod;
				}
			}
			ans=(ans+nw);
		}
	}
	pair<int,int> nw=make_pair(0,1);
	for (int i=1; i<=n; i++) if (!v[i].empty())
	{
		nw.first++;
		nw.second=1ll*nw.second*v[i].size()%mod;
	}
	ans=(ans+nw);
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}