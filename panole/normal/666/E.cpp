#include<bits/stdc++.h>
using namespace std;

int Tn;
int sum[600010],poo[600010],id[1200010];
int n,m,cnt,fa[1200010],ch[1200010][27],f[21][1200010],len[50010],st[50010],po[1200010],ma[1200010],la,p[600010],hd[1200010],rt[1200010];
struct node{int l,r,ord,dep,next;}q[500010],T[500010];
pair<int,int> ans[500010];
char s[600010],S[50010];
vector<pair<int,int> > v[1200010];
struct seg{int ls,rs; pair<int,int> ma;}t[25300010];

void add(int i,int l,int r,int x)
{
	if (l==r) 
	{
		t[i].ma=make_pair(t[i].ma.first+1,-l);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) add(t[i].ls?t[i].ls:t[i].ls=(++cnt),l,mid,x);
	else add(t[i].rs?t[i].rs:t[i].rs=(++cnt),mid+1,r,x);
	t[i].ma=max(t[t[i].ls].ma,t[t[i].rs].ma);
}

pair<int,int> query(int i,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return t[i].ma;
	int mid=(l+r)>>1;
	if (qr<=mid) return t[i].ls?query(t[i].ls,l,mid,ql,qr):make_pair(0,0);
	if (ql>mid) return t[i].rs?query(t[i].rs,mid+1,r,ql,qr):make_pair(0,0);
	return max(t[i].ls?query(t[i].ls,l,mid,ql,mid):make_pair(0,0),t[i].rs?query(t[i].rs,mid+1,r,mid+1,qr):make_pair(0,0));
}

void merge(int i,int I,int l,int r)
{
	if (l==r) {t[i].ma.first+=t[I].ma.first; return;}
	int mid=(l+r)>>1;
	if (t[i].ls) {if (t[I].ls) merge(t[i].ls,t[I].ls,l,mid);} else t[i].ls=t[I].ls;
	if (t[i].rs) {if (t[I].rs) merge(t[i].rs,t[I].rs,mid+1,r);} else t[i].rs=t[I].rs;
	t[i].ma=max(t[t[i].ls].ma,t[t[i].rs].ma);
}

bool cmp(node a,node b) {return a.dep<b.dep;}
void addq(int x,int l,int r,int dep,int ord) {q[++cnt]=(node){l,r,ord,dep,hd[x]},hd[x]=cnt;}

void ins(int c)
{
	int pp=la,np=(++cnt); ma[la=np]=ma[pp]+1;
	while (pp&&!ch[pp][c]) ch[pp][c]=np,pp=fa[pp];
	if (!pp) fa[np]=1; else
	{
		int q=ch[pp][c];
		if (ma[q]==ma[pp]+1) fa[np]=q; else
		{
			int nq=(++cnt); ma[nq]=ma[pp]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[nq]));
			fa[nq]=fa[q],fa[q]=fa[np]=nq;
			while (ch[pp][c]==q) ch[pp][c]=nq,pp=fa[pp];
		}
	}
	po[np]=n-ma[np];
	p[po[np]]=np;
}

int getpo(int l,int r)
{
	int x=p[l];
	for (int j=20; j>=0; j--)
		if (ma[f[j][x]]>=r-l+1) x=f[j][x];
	return x;
}

void dfs(int x)
{
	rt[x]=(++cnt);
	for (int i=0; i<=26; i++)
		if (ch[x][i]) dfs(ch[x][i]),merge(rt[x],rt[ch[x][i]],1,50000);
	sort(v[x].begin(),v[x].end()),Tn=0;
	for (int i=hd[x]; i; i=q[i].next) T[++Tn]=q[i];
	sort(T+1,T+1+Tn,cmp); int p=Tn;
	for (int sz=v[x].size(),i=sz-1; i>=0; i--)
	{
		while (p&&T[p].dep>v[x][i].first) ans[T[p].ord]=query(rt[x],1,50000,T[p].l,T[p].r),p--;
		add(rt[x],1,50000,v[x][i].second);
	}
	while (p) ans[T[p].ord]=query(rt[x],1,50000,T[p].l,T[p].r),p--;
}

int main()
{
	scanf("%s",s),n=strlen(s);
	scanf("%d",&m),len[0]=n,st[0]=0;
	for (int i=1; i<=m; i++)
	{
		scanf("%s",S),len[i]=strlen(S),n+=len[i]+1;
		st[i]=st[i-1]+len[i-1]+1,s[st[i]-1]='a'+26;
		for (int j=0; j<len[i]; j++) s[st[i]+j]=S[j];
	}
	cnt=la=1,fa[1]=ma[1]=0,poo[0]=1;
	for (int i=n-1; i>=0; i--) ins(s[i]-'a');
	for (int i=1; i<=cnt; i++) sum[ma[i]]++;
	for (int i=1; i<=n; i++) sum[i]+=sum[i-1],poo[i]=sum[i-1];
	for (int i=1; i<=cnt; i++) id[poo[ma[i]]++]=i;
	for (int i=cnt; i; i--) po[fa[id[i]]]=po[id[i]];
	for (int i=1; i<=cnt; i++) memset(ch[i],0,sizeof(ch[i]));
	for (int i=2; i<=cnt; i++) ch[fa[i]][s[po[i]+ma[fa[i]]]-'a']=i;
	for (int i=1; i<=cnt; i++) f[0][i]=fa[i];
	for (int j=1; j<=20; j++)
		for (int i=1; i<=cnt; i++) f[j][i]=f[j-1][f[j-1][i]];
	for (int i=1; i<=m; i++)
		for (int x,j=st[i]; j<st[i]+len[i]; j++)
			v[getpo(j,st[i]+len[i]-1)].push_back(make_pair(st[i]+len[i]-j,i));
	scanf("%d",&m),cnt=0;
	for (int i=1; i<=m; i++)
	{
		int l,r,pl,pr;
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		addq(getpo(pl-1,pr-1),l,r,pr-pl+1,i);
	}
	cnt=0,dfs(1);
	for (int i=1; i<=m; i++) 
	{
		if (ans[i].first==0) printf("%d %d\n",q[i].l,0);
		else printf("%d %d\n",-ans[i].second,ans[i].first);
	}
	return 0;
}