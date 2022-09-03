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

struct arrow
{
	int type;//type=0: vertical type=1: horizontal
	int x,y,yy,i;
	void in(int i)
	{
		this->i=i;
		int x,y,xx,yy;get2(x,y);get2(xx,yy);
		if(x==xx)
		{
			this->x=x;this->y=y;this->yy=yy;
			type=0;
		}
		else
		{
			this->x=y;this->y=x;this->yy=xx;
			type=1;
		}
	}
};
arrow a[100111];

int n,q,qnxt[100111];
int b,x[100111],y[100111],dir[100111];
LL t[100111];

int nxt[50][100111];
LL len[50][100111];double tlen[50][100111];

void work(int tp)
{
	vector<pair<int,pii> > v;set<pii>st;
	for(int i=1;i<=n;i++)
	{
		if(a[i].type==tp)v.pb(mp(a[i].x,mp(1,i)));
		else if(a[i].y<=a[i].yy)
		{
			v.pb(mp(a[i].y,mp(0,i)));
			v.pb(mp(a[i].yy,mp(3,i)));
		}
		else
		{
			v.pb(mp(a[i].yy,mp(0,i)));
			v.pb(mp(a[i].y,mp(3,i)));
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(tp==0&&dir[i]<=1)
			v.pb(mp(x[i],mp(2,i)));
		else if(tp==1&&dir[i]>=2)v.pb(mp(y[i],mp(2,i)));
	}
	sort(v.begin(),v.end());
	for(int id=0,nt=0;id<(int)v.size();id=nt)
	{
		for(;nt<(int)v.size()&&v[id].ff==v[nt].ff;nt++)
		{
			if(v[nt].ss.ff==1)
			{
				int i=v[nt].ss.ss;
				st.insert(mp(a[i].y,i));
				st.insert(mp(a[i].yy,i));
			}
		}
		for(int j=id;j<nt;j++)
		{
			pair<int,pii>&now=v[j];
			int i=now.ss.ss;
			if(now.ss.ff==0)st.insert(mp(a[i].x,i));
			else if(now.ss.ff==3)st.erase(mp(a[i].x,i));
			else if(now.ss.ff==1)
			{
				st.erase(mp(a[i].y,i));
				st.erase(mp(a[i].yy,i));
				auto p=st.lower_bound(mp(a[i].y,0));
				if(a[i].y<=a[i].yy&&p!=st.end())nxt[0][i]=p->ss;
				else if(a[i].y>a[i].yy&&p!=st.begin())
				{
					--p;
					nxt[0][i]=p->ss;
				}
				st.insert(mp(a[i].y,i));
				st.insert(mp(a[i].yy,i));
			}
			else
			{
				int pos;if(tp==0)pos=y[i];else pos=x[i];
				if(dir[i]%2==0)
				{
					auto p=st.lower_bound(mp(pos,0));
					if(p!=st.end())qnxt[i]=p->ss;
				}
				else if(dir[i]%2)
				{
					auto p=st.lower_bound(mp(pos,inf));
					if(p!=st.begin())
					{
						--p;
						qnxt[i]=p->ss;
					}
				}
			}
		}
		for(int j=id;j<nt;j++)
		{
			if(v[j].ss.ff==1)
			{
				int i=v[j].ss.ss;
				st.erase(mp(a[i].y,i));
				st.erase(mp(a[i].yy,i));
			}
		}
	}
}

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

void find_pos(int x,int y,int d,int i,LL len)
{
	int ansx,ansy;
	if(i==0)
	{
		ansx=max(min(b+0ll,x+len*dx[d]),0ll);
		ansy=max(min(b+0ll,y+len*dy[d]),0ll);
	}
	else if(a[i].type==(d>>1))
	{
		if(a[i].type==0)
		{
			ansx=a[i].x;
			if(a[i].yy>y)ansy=y+len;
			else ansy=y-len;
		}
		else
		{
			if(a[i].yy>x)ansx=x+len;
			else ansx=x-len;
			ansy=a[i].x;
		}
	}
	else
	{
		int l1;
		if(a[i].type==0)l1=abs(x-a[i].x);
		else l1=abs(y-a[i].x);
		if(len<=l1)
		{
			if(a[i].type==0)
			{
				if(x<a[i].x)ansx=x+len;
				else ansx=x-len;
				ansy=y;
			}
			else
			{
				ansx=x;
				if(y<a[i].x)ansy=y+len;
				else ansy=y-len;
			}
		}
		else
		{
			len-=l1;
			if(a[i].type==0)
			{
				ansx=a[i].x;
				if(y<a[i].yy)ansy=y+len;
				else ansy=y-len;
			}
			else
			{
				if(x<a[i].yy)ansx=x+len;
				else ansx=x-len;
				ansy=a[i].x;
			}
		}
	}
	printf("%d %d\n",ansx,ansy);
}
int main()
{
	get2(n,b);
	for(int i=1;i<=n;i++)a[i].in(i);
	get1(q);
	char op[3];
	for(int i=1;i<=q;i++)
	{
		get2(x[i],y[i]);scanf("%s",op);get1(t[i]);
		if(op[0]=='U')dir[i]=0;
		else if(op[0]=='D')dir[i]=1;
		else if(op[0]=='R')dir[i]=2;
		else dir[i]=3;
	}
	
	work(0);
	work(1);
	
	for(int i=1;i<=n;i++)
	{
		int&j=nxt[0][i];
		if(!j)continue;
		if(a[i].type==a[j].type)len[0][i]=abs(a[i].yy-a[j].yy);
		else len[0][i]=abs(a[i].yy-a[j].x)+abs(a[j].yy-a[i].x);
		tlen[0][i]=len[0][i];
	}
	for(int i=1;i<50;i++)for(int j=1;j<=n;j++)
	{
		nxt[i][j]=nxt[i-1][nxt[i-1][j]];
		len[i][j]=len[i-1][j]+len[i-1][nxt[i-1][j]];
		tlen[i][j]=tlen[i-1][j]+tlen[i-1][nxt[i-1][j]];
	}
	for(int i=1;i<=q;i++)
	{
		int l1,j=qnxt[i];
		if(a[j].type==0)l1=abs(a[j].x-x[i])+abs(a[j].yy-y[i]);
		else l1=abs(a[j].x-y[i])+abs(a[j].yy-x[i]);
		if(!j||t[i]<=l1)find_pos(x[i],y[i],dir[i],j,t[i]);
		else
		{
			t[i]-=l1;
			for(int d=49;d>=0;d--)if(nxt[d][j]&&len[d][j]<=t[i]&&tlen[d][j]<=1e17)
			{
				t[i]-=len[d][j];
				j=nxt[d][j];
			}
			int tdir=a[j].type*2+(a[j].yy<a[j].y);
			if(a[j].type==0)find_pos(a[j].x,a[j].yy,tdir,nxt[0][j],t[i]);
			else find_pos(a[j].yy,a[j].x,tdir,nxt[0][j],t[i]);
		}
	}
	return 0;
}