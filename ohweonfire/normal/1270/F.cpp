// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=200111;
const int magic=500;

char s[maxn];
int p[maxn],n,vl[maxn],vr[maxn],val[maxn];
LL ans;

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	memset(vl,-1,sizeof(vl));
	memset(vr,-1,sizeof(vr));
	vl[0]=vr[0]=0;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]+s[i]-'0';
		vr[p[i]]=i;
		if(vl[p[i]]==-1)vl[p[i]]=i;
	}
	int m=p[n];LL cnt=0;
	for(int i=1;i<magic&&i<=m;i++)
	{
		for(int l=0,r=i;r<=m;l++,r++)
		{
			for(int j=vl[l];j<=vr[l];j++)
			{
				int lb=vl[r]-j,rb=vr[r]-j;
				rb=rb/i*i;lb=(lb+i-1)/i*i;lb=max(lb,i*(n/magic+1));
				if(lb>rb)continue;
				ans+=(rb-lb)/i+1;
				cnt++;
			}
		}
	}
	for(int k=1;k<=n/magic;k++)
	{
		for(int i=0;i<=n;i++)val[i]=i-k*p[i];
		sort(val,val+n+1);
		int len=0;
		for(int i=0;i<=n;i++)
		{
			if(i==0||val[i]!=val[i-1])len=0;
			ans+=len;
			len++;
		}
	}
	printendl(ans);
	return 0;
}