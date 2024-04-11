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

const int maxn=10111;

string name[]={"Gryffindor","Hufflepuff","Ravenclaw","Slytherin"};

int n;
char s[maxn];
set<vector<int> >vs[maxn];

int main()
{
	get1(n);scanf("%s",s+1);
	
	vector<int> v(4);for(int i=0;i<4;i++)v.pb(0);
	vs[1].insert(v);
	for(int i=1;i<=n;i++)
	{
		int val;
		if(s[i]=='?')val=-1;
		else if(s[i]=='G')val=0;
		else if(s[i]=='H')val=1;
		else if(s[i]=='R')val=2;
		else val=3;
		for(auto v:vs[i])
		{
			vector<int> nv=v;
			if(val!=-1)
			{
				nv[val]++;
				vs[i+1].insert(nv);
			}
			else
			{
				int mn=inf;for(int j=0;j<4;j++)mn=min(mn,v[j]);
				for(int j=0;j<4;j++)if(v[j]==mn)
				{
					nv[j]++;
					vs[i+1].insert(nv);
					nv[j]--;
				}
			}
		}
	}
	bool ans[4]={};
	for(auto v:vs[n+1])
	{
		int mn=inf;for(int j=0;j<4;j++)mn=min(mn,v[j]);
		for(int i=0;i<4;i++)if(v[i]==mn)ans[i]=1;
	}
	for(int i=0;i<4;i++)if(ans[i])printf("%s\n",name[i].c_str());
	return 0;
}