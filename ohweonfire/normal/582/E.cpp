// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();
	if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
	return true;
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

const int maxn=511;
const int mod=1e9+7;
const int N=1<<16;
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

#define getcode(i,j) (((i)>>(j))&1)
struct data
{
	int a[N];
	data(){memset(a,0,sizeof(a));}
	data(int b[N]){memcpy(a,b,sizeof(a));}
	data operator +(const data&b)const
	{
		data ret;
		for(int i=0;i<N;i++)
		{
			ret.a[i]=a[i]+b.a[i];
			if(ret.a[i]>=mod)ret.a[i]-=mod;
		}
		return ret;
	}
};
data upper[4],lower[4],none;

int ta[N],tb[N];
data AND(const data&a,const data&b)
{
	memcpy(ta,a.a,sizeof(ta));memcpy(tb,b.a,sizeof(tb));
	for(int i=0;i<16;i++)for(int j=0;j<N;j++)if(getcode(j,i))
	{
		add(ta[j^(1<<i)],ta[j]);
		add(tb[j^(1<<i)],tb[j]);
	}
	for(int i=0;i<N;i++)ta[i]=(LL)ta[i]*tb[i]%mod;
	for(int i=0;i<16;i++)for(int j=0;j<N;j++)if(getcode(j,i))add(ta[j^(1<<i)],mod-ta[j]);
	return data(ta);
}
data OR(const data&a,const data&b)
{
	memcpy(ta,a.a,sizeof(ta));memcpy(tb,b.a,sizeof(tb));
	for(int i=0;i<16;i++)for(int j=0;j<N;j++)if(getcode(j,i))
	{
		add(ta[j],ta[j^(1<<i)]);
		add(tb[j],tb[j^(1<<i)]);
	}
	for(int i=0;i<N;i++)ta[i]=(LL)ta[i]*tb[i]%mod;
	for(int i=0;i<16;i++)for(int j=0;j<N;j++)if(getcode(j,i))add(ta[j],mod-ta[j^(1<<i)]);
	return data(ta);
}

char s[maxn];
int n,m;

data parse(int l,int r)
{
	if(l==r)
	{
		if(s[l]>='A'&&s[l]<='D')return upper[s[l]-'A'];
		else if(s[l]>='a'&&s[l]<='d')return lower[s[l]-'a'];
		else return none;
	}
	int match=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='(')match++;
		else if(s[i]==')')
		{
			match--;
			if(match)continue;
			data vl=parse(l+1,i-1),vr=parse(i+3,r-1);
			if(s[i+1]=='&')return AND(vl,vr);
			else if(s[i+1]=='|')return OR(vl,vr);
			else return AND(vl,vr)+OR(vl,vr);
		}
	}
}

int qmsk[16],qval[16];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	
	for(int i=0;i<4;i++)
	{
		int msk1=0,msk2=0;
		for(int j=0;j<16;j++)if(getcode(j,i))msk1|=1<<j;else msk2|=1<<j;
		upper[i].a[msk1]=1;
		lower[i].a[msk2]=1;
		none=none+upper[i]+lower[i];
	}
	data ans=parse(1,n);
	get1(m);
	for(int i=0,v;i<m;i++)
	{
		qmsk[i]=0;
		for(int j=0;j<4;j++)
		{
			get1(v);
			qmsk[i]|=v<<j;
		}
		get1(qval[i]);
	}
	int sum=0;
	for(int i=0;i<N;i++)
	{
		bool ok=1;
		for(int j=0;j<m&&ok;j++)if(getcode(i,qmsk[j])!=qval[j])ok=0;
		if(ok)add(sum,ans.a[i]);
	}
	printendl(sum);
	return 0;
}