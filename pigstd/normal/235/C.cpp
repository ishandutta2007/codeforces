#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e9;
const int M=1e6+10;
int n,m,p[M<<1];
char s[M<<1];
struct node
{
	int link,len,cnt;
	map<int,int>e;
}t[M<<1];int tot,now;

void init(){t[0].link=-1;}

void insert(int x)
{
	int cur=++tot,p=now;t[cur].len=t[now].len+1,t[cur].cnt=1;
	while(p!=-1&&!t[p].e.count(x))t[p].e[x]=cur,p=t[p].link;
	if (p==-1){now=cur;return;}
	int q=t[p].e[x];
	if (t[q].len==t[p].len+1)
	{
		t[cur].link=q;
		now=cur;return;
	}
	t[++tot]=t[q];t[tot].len=t[p].len+1;t[tot].cnt=0;
	while(p!=-1&&t[p].e[x]==q)t[p].e[x]=tot,p=t[p].link;
	t[q].link=t[cur].link=tot;now=cur;
}

bool cmp(int a,int b){return t[a].len>t[b].len;}

void solve()
{
	scanf("%s",s);int n=strlen(s),res=0,now=0,len=0;
	for (int i=0;i<n;i++)s[i+n]=s[i];
	vector<pii>v;
	for (int i=0;i<2*n;i++)
	{
		int c=s[i]-'a'+1;
		if (len==n)
		{
			if (len-1==t[t[now].link].len)now=t[now].link;
			len--;
		}
		while(now!=0&&!t[now].e.count(c))now=t[now].link,len=t[now].len;
		if (t[now].e.count(c))now=t[now].e[c],len++;
		if (len==n&&t[now].cnt!=0)
			res+=t[now].cnt,v.pb(mp(now,t[now].cnt)),t[now].cnt=0;
	}
	for (auto x:v)t[x.x].cnt=x.y;
	printf("%d\n",res);
}

signed main()
{
	scanf("%s",s);int m=strlen(s);init();
	for (int i=0;i<m;i++)insert(s[i]-'a'+1);
	for (int i=1;i<=tot;i++)p[i]=i;
	sort(p+1,p+1+tot,cmp);
	for (int i=1;i<=tot;i++)t[t[p[i]].link].cnt+=t[p[i]].cnt;
	WT solve();
	return 0;
}
/*
baabaa
1
a
*/