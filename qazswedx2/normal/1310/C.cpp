#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
struct pt
{
	string s;
	int id;
	bool operator<(const pt x) const
	{
		return s<x.s;
	}
}p[100005];
int n,m,fail[100005],cnt=1,las=1,len[100005],q[100005],head,tail,vis[100005];
int ch[100005][26],g[100005];
ll k,f[1005][1005];
char s[100005],sr[100005],str1[100005];
string a[10005];
void ins(int c)
{
	int p=las,np=++cnt;
	las=np;
	len[np]=len[p]+1;
	while(p&&!ch[p][c]) ch[p][c]=np,p=fail[p];
	if(!p) fail[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[q]==len[p]+1) fail[np]=q;
		else
		{
			int nq=++cnt;
			len[nq]=len[p]+1;
			for(int i=0;i<26;i++)
				ch[nq][i]=ch[q][i];
			fail[nq]=fail[q];
			fail[np]=fail[q]=nq;
			while(p&&ch[p][c]==q) ch[p][c]=nq,p=fail[p];
		}
	}
}
ll addmod(ll x)
{
	return x>k?k+1:x;
}
bool check(const string& str)
{
//	printf("check:str=");
//	cout<<str<<'\n';
	memset(f,0,sizeof(f));
	f[0][0]=1,f[0][1]=-1;
	int sz=str.size();
	s[n+1]='z'+1;
	for(int i=1;i<=n;i++)
	{
		g[i]=0;
		while(g[i]<sz&&s[i+g[i]]==str[g[i]]) g[i]++;
		if(g[i]<sz&&s[i+g[i]]<str[g[i]]) g[i]=-1;
		if(g[i]==sz) g[i]--;
	//	printf("%d ",g[i]);
	}
//	printf("\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(j) f[i][j]=addmod(f[i][j]+f[i][j-1]);
			if(g[j+1]!=-1)
			{
		//		printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
				if(f[i][j])
					f[i+1][j+g[j+1]+1]=addmod(f[i+1][j+g[j+1]+1]+f[i][j]);
			}
		}
	/*for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%lld ",f[i][j]);
		printf("\n");
	}*/
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans=addmod(ans+f[m][i]);
	//printf("ans=%d\n",ans);
	if(ans>=k) return 1;
	return 0;
}
int main()
{
	scanf("%d%d%lld%s",&n,&m,&k,s+1);
	for(int i=1;i<=n;i++)
		sr[n-i+1]=s[i];
	for(int i=1;i<=n;i++)
		ins(sr[i]-'a');
	head=0,tail=1;
	q[1]=1;
	vis[1]=1;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=0;i<26;i++)
			if(ch[u][i])
			{
				int v=ch[u][i];
				if(vis[v]) continue;
				vis[v]=1;
				a[v]=a[u];
				a[v].push_back(i+'a');
				q[++tail]=v;
			}
	}
	for(int i=2;i<=cnt;i++)
	{
		p[i].s=a[i];
		reverse(p[i].s.begin(),p[i].s.end());
		p[i].id=i;
	//	printf("i=%d,id=%d,s=",i,p[i].id);
	//	cout<<p[i].s<<'\n';
	}
	sort(p+2,p+cnt+1);
	int l=2,r=cnt,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(p[mid].s)) l=mid+1;
		else r=mid-1;
	}
	string str=p[r].s;
	int nl=p[r].s.size(),id=-1;
	for(int i=1;i<=n;i++)
	{
		int fl=1;
		for(int j=i,k=0;k<nl;k++,j++)
			if(s[j]!=str[k])
			{
				fl=0;
				break;
			}
		if(fl)
		{
			id=i;
			break;
		}
	}
	int ll=len[fail[p[r].id]]+1,rr=len[p[r].id];
	//printf("ll=%d,rr=%d\n",ll,rr);
	while(ll<=rr)
	{
		mid=(ll+rr)/2;
		str.resize(mid);
		for(int i=0,j=id;i<mid;i++,j++)
			str[i]=s[j];
		if(check(str)) ll=mid+1;
		else rr=mid-1;
	}
	if(rr<=len[p[r].id])
	{
		for(int i=0,j=id;i<rr;i++,j++)
			str1[i]=s[j];
		printf("%s",str1);
		return 0;
	}
/*	int sz=p[l].s.size();
	for(int i=0,j=0;j<sz;i++,j++)
		str1[i]=p[l].s[j];
	printf("%s",str1);*/
	return 0;
}