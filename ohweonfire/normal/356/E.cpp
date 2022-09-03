// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const uLL base=43;
uLL power[100111],pre[100111];
uLL calhash(int l,int r){return (pre[r]-pre[l-1])*power[100100-l];}

#define getcnt(l,r,t) (pcnt[r][t]-pcnt[(l)-1][t])
char s[100111];
int n,pcnt[100111][26];
bool ok[100111][20];
LL s1[100111],s2[100111][26],sum;
pii getdif(int l,int r,int ll,int rr)
{
	if(l==r)return mp(l,ll);
	int m=(l+r)>>1,mm=(ll+rr)>>1;
	if(calhash(l,m)==calhash(ll,mm))return getdif(m+1,r,mm+1,rr);
	else if(calhash(m+1,r)==calhash(mm+1,rr))return getdif(l,m,ll,mm);
	else return mp(-1,-1);
}
int main()
{
	power[0]=1;for(int i=1;i<100111;i++)power[i]=power[i-1]*base;
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+power[i]*(s[i]-'a'+1);
		memcpy(pcnt[i],pcnt[i-1],sizeof(pcnt[i]));
		pcnt[i][s[i]-'a']++;
	}
	
	for(int l=1;(1<<l)<=n+1;l++)
	{
		int len=(1<<l-1)-1;
		for(int i=len+1;i+len<=n;i++)
		{
			if(len==0)ok[i][l]=1;
			else ok[i][l]=(getcnt(i-len,i+len,s[i]-'a')==1)&&ok[i+i-len-1>>1][l-1]&&calhash(i-len,i-1)==calhash(i+1,i+len);
			if(ok[i][l])
			{
				sum+=1ll*(len+len+1)*(len+len+1);
				s1[i-len]+=1ll*(len+len+1)*(len+len+1);s1[i+len+1]-=1ll*(len+len+1)*(len+len+1);
			}
			else if(getcnt(i-len,i+len,s[i]-'a')<=2)
			{
				pii dif=getdif(i-len,i-1,i+1,i+len);
				if(dif.ff!=-1)
				{
					if(ok[i+i+len+1>>1][l-1]&&s[dif.ss]!=s[i])s2[dif.ff][s[dif.ss]-'a']+=1ll*(len+len+1)*(len+len+1);
					if(ok[i+i-len-1>>1][l-1]&&s[dif.ff]!=s[i])s2[dif.ss][s[dif.ff]-'a']+=1ll*(len+len+1)*(len+len+1);
				}
			}
			if(calhash(i-len,i-1)==calhash(i+1,i+len)&&ok[i+i-len-1>>1][l-1])
			{
				for(int j=0;j<26;j++)if(getcnt(i-len,i+len,j)==0)
					s2[i][j]+=1ll*(len+len+1)*(len+len+1);
			}
		}
	}
	LL ans=sum;
	for(int i=1;i<=n;i++)s1[i]+=s1[i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)if(s[i]!=j+'a')
			ans=max(ans,sum-s1[i]+s2[i][j]+1);
	}
	printendl(ans);
	return 0;
}