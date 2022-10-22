#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int B=1<<18;
const int M=40;
int a,x,len;
string s;

map<int,int>t;

void mod(int &x){if ((x>>len)&1)x^=a;}
int mul(int a,int b)
{
	int res=0;
	for (int i=0;i<len;i++)
	{
		if ((b>>i)&1)res^=a;
		a=a<<1;mod(a);
	}
	return res;
}

signed main()
{
	cin>>s;
	for (int i=0;i<(int)(s.size());i++)a|=(int)(s[i]-'0')<<i;
	if (a==0)return puts("-1"),0;
	while(a&1^1)a>>=1,x++;
	cerr<<a<<' '<<x<<'\n';
	if (a==1)return cout<<x+1<<' '<<x+2<<'\n',0;
	for (int i=0;i<=40;i++)
		if ((a>>i)&1)len=i;
	int now=1;t[now]=0;
	for (int i=1;i<=B;i++)
	{
		now<<=1;mod(now);t[now]=i;
		if (now==1)return cout<<x+1<<' '<<x+i+1<<'\n',0;
	}
	int tmp=now;
	for (int i=2;i<=B;i++)
	{
		now=mul(now,tmp);
		if (t.find(now)!=t.end())
			return cout<<x+1<<' '<<x+i*B-t[now]+1<<'\n',0;
	}
	return 0;
}