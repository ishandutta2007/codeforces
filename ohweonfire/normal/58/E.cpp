// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
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
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int encode(int a,int b,int c,int aa,int bb,int cc,int add){return a*8*8*8*8*8*2+b*8*8*8*8*2+c*8*8*8*2+aa*8*8*2+bb*8*2+cc*2+add;}
void decode(int msk,int&a,int&b,int&c,int&aa,int&bb,int&cc,int&add)
{
	add=msk%2;msk/=2;
	cc=msk%8;msk/=8;
	bb=msk%8;msk/=8;
	aa=msk%8;msk/=8;
	c=msk%8;msk/=8;
	b=msk%8;msk/=8;
	a=msk%8;msk/=8;
}

int dp[1000111],pre[1000111],prea[1000111],preb[1000111],prec[1000111];

string a,b,c;
int main()
{
	string s;
	cin>>s;
	int p1=0;while(s[p1]!='+')p1++;
	int p2=0;while(s[p2]!='=')p2++;
	a=s.substr(0,p1);
	b=s.substr(p1+1,p2-p1-1);
	c=s.substr(p2+1);
	reverse(a.begin(),a.end());reverse(b.begin(),b.end());reverse(c.begin(),c.end());
	
	memset(dp,63,sizeof(dp));dp[0]=0;
	int tmp=-1;
	for(int ta=0;ta<=(int)a.size();ta++)for(int tb=0;tb<=(int)b.size();tb++)for(int tc=0;tc<=(int)c.size();tc++)
	{
		for(int za=0;za<8;za++)for(int zb=0;zb<8;zb++)for(int zc=0;zc<8;zc++)for(int add=0;add<2;add++)
		{
			int msk=encode(ta,tb,tc,za,zb,zc,add);if(dp[msk]==inf)continue;
			if(ta==(int)a.size()&&tb==(int)b.size()&&tc==(int)c.size()&&add==0)
			{
				if(tmp==-1||dp[tmp]>dp[msk])tmp=msk;
				continue;
			}
			for(int i=0;i<10;i++)for(int j=0;j<10;j++)
			{
				int nta,ntb,ntc,nza=za+1,nzb=zb+1,nzc=zc+1,nadd,k=i+j+add,w=0;
				nadd=k/10;k%=10;
				nta=ta+(ta<(int)a.size()&&a[ta]==i+'0');
				ntb=tb+(tb<(int)b.size()&&b[tb]==j+'0');
				ntc=tc+(tc<(int)c.size()&&c[tc]==k+'0');
				if(nta==ta&&ntb==tb&&ntc==tc)continue;
				if(i){w+=nza;nza=0;}
				if(j){w+=nzb;nzb=0;}
				if(k){w+=nzc;nzc=0;}
				if(nza>6||nzb>6||nzc>6)continue;
				int nmsk=encode(nta,ntb,ntc,nza,nzb,nzc,nadd);
				if(dp[nmsk]>dp[msk]+w)
				{
					dp[nmsk]=dp[msk]+w;
					pre[nmsk]=msk;
					prea[nmsk]=i;preb[nmsk]=j;prec[nmsk]=k;
				}
			}
		}
	}
	string aa,bb,cc;
	while(tmp)
	{
		aa=aa+char(prea[tmp]+'0');
		bb=bb+char(preb[tmp]+'0');
		cc=cc+char(prec[tmp]+'0');
		tmp=pre[tmp];
	}
	while(aa[0]=='0')aa=aa.substr(1);
	while(bb[0]=='0')bb=bb.substr(1);
	while(cc[0]=='0')cc=cc.substr(1);
	cout<<aa<<'+'<<bb<<'='<<cc<<endl;
	return 0;
}