//AFO countdown:24 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int Mod=998244353;
const int base=27;
const int M=2e5+10;
int n,m,ans,ht[M],val[M];
int top,z[M];
pair<int,int>ll[M];
pair<int,string>p[M];
string ss[M],s[M];
vector<int>f1[M],f2[M];
int son[M][30],cnt;
vector<int>vec[M],sum[M];

void insert(string s,int p,int val){
	int now=0;vec[0].pb(p),f1[p][m]=now;
	if (sum[now].size()==0)sum[now].pb(val);
	else sum[now].pb(val+sum[now][sum[now].size()-1]);
	for (int i=m-1;i>=0;i--){
		if (son[now][s[i]-'a']==0)
			son[now][s[i]-'a']=++cnt;
		now=son[now][s[i]-'a'];f1[p][i]=now;
		vec[now].pb(p);
		if (sum[now].size()==0)sum[now].pb(val);
		else sum[now].pb(val+sum[now][sum[now].size()-1]);
	}
}

void clear(){
	for (int i=0;i<=cnt;i++){
		for (int j=0;j<26;j++)son[i][j]=0;
		vec[i].clear(),sum[i].clear();
	}cnt=0;
}

int calc(int u,int l,int r)
{
	int tl=0,tr=vec[u].size()-1,p1=-1,p2=-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (vec[u][Mid]>=l)p1=Mid,tr=Mid-1;
		else tl=Mid+1;
	}
	tl=0,tr=vec[u].size()-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (vec[u][Mid]<=r)p2=Mid,tl=Mid+1;
		else tr=Mid-1;
	}
	if (p1==-1||p2==-1)return 0;
	else if (p1==0)return sum[u][p2];
	else return sum[u][p2]-sum[u][p1-1];
}

void solve(int l,int r){
	ans+=1337*(n-(r-l+1))*(r-l+1);
	int n=0;ans+=2*(r-l+1)*(r-l);top=0;
	for (int i=l;i<=r;i++)
		if (p[i].y==p[i-1].y)val[n]++;
		else val[++n]=1,s[n]=p[i].y;
	for (int i=1;i<n;i++){
		ht[i]=0;
		while(ht[i]!=m&&s[i][ht[i]]==s[i+1][ht[i]])
			ht[i]++;
	}clear();
	for (int i=1;i<=n;i++){
		f1[i].clear(),f1[i].resize(m+1),insert(s[i],i,val[i]);
		f2[i].clear();f2[i].resize(m+1);int la=0;
		for (int j=1;j<m;j++){
			if (s[i][j]<s[i][j-1])la=j;
			f2[i][j]=la;
//			cout<<i<<' '<<j<<' '<<f2[i][j]<<endl;
		}
	}//puts("qwq");
	for (int i=n-1;i>=1;i--){
		while(top>0&&ht[i]<=ht[z[top]])top--;
		z[++top]=i;ll[top]=mp(i+1,top==1?n:ll[top-1].x-1);
		for (int j=1;j<=top;j++){
			int x=ht[z[j]],L=ll[j].x,R=ll[j].y;
			int tl=0,tr=m-1,p=0;
			while(tl<=tr)
			{
				int Mid=(tl+tr)>>1;
				if (f2[i][Mid]<=x)p=Mid,tl=Mid+1;
				else tr=Mid-1;
			}
			int u=f1[i][p+1];
//			puts("????");
			ans-=2*val[i]*calc(u,L,R);
//			cout<<i<<' '<<j<<' '<<2*val[i]*calc(u,L,R)<<endl;
		}
	}
	for (int i=1;i<=n;i++)
		ans-=2*val[i]*(val[i]-1);
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++){
		cin>>ss[i];int res=0;
		string c=ss[i];
		sort(c.begin(),c.end());
		for (int j=0;j<c.size();j++)
			res=(res*base+c[j]-'a'+1)%Mod;
		p[i]=mp(res,ss[i]);
	}
	m=ss[1].size();
	sort(p+1,p+1+n);int la=1;
	for (int i=2;i<=n+1;i++)
		if (p[i].x!=p[i-1].x)solve(la,i-1),la=i;
	cout<<ans/2<<endl;
	return 0;
}
/*
3
bac
abc
acb
*/