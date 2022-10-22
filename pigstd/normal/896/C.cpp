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

const int Mod=1e9+7;
const int M=1e5+10;
int n,m,sd,vm,a[M];
struct node
{
	int l,r,v;
//	bool operator < (const node&o)const{return l<o.l;}
	friend bool operator < (const node&x,const node&y){return x.l<y.l;}
};
set<node>s;

int rnd()
{
	int res=sd;
	sd=(sd*7+13)%Mod;
	return res;
}

void split(int p)
{
	for (auto x:s)
	{
		if (x.r>=p)
		{
			s.erase(x);s.insert((node){p,x.r,x.v});
			if (x.l!=p)s.insert((node){x.l,p-1,x.v});
			break;
		}
	}
}

int poww(int a,int b,int mod)
{
	a%=mod;int res=1;
	while(b)
	{
		if (b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}return res;
}

signed main()
{
	n=read(),m=read(),sd=read(),vm=read();
	for (int i=1;i<=n;i++)a[i]=rnd()%vm+1,s.insert((node){i,i,a[i]});
	while(m--)
	{
		int opt,l,r,X,Y=-1;
		opt=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
		if (l>r)swap(l,r);
		if (opt==3)X=rnd()%(r-l+1)+1;
		else X=rnd()%vm+1;
		if (opt==4)Y=rnd()%vm+1;
		if (opt==1)
		{
			split(l),split(r+1);
			set<node>s2,s3;
			for (auto x:s)
				if (x.l>=l&&x.r<=r)s2.insert((node){x.l,x.r,x.v+X}),s3.insert(x);
			for (auto x:s3)s.erase(x);
			for (auto x:s2)s.insert(x);
		}
		if (opt==2)
		{
			split(l),split(r+1);
			set<node>s2;
			for (auto x:s)
				if (x.l>=l&&x.r<=r)s2.insert(x);
			for (auto x:s2)s.erase(x);
			s.insert((node){l,r,X});
		}
		if (opt==3)
		{
			split(l),split(r+1);
			vector<pair<int,int>>v;
			for (auto x:s)if (x.l>=l&&x.r<=r)v.pb(mp(x.v,x.r-x.l+1));
			sort(v.begin(),v.end());
			for (auto x:v)
			{
				if (X>x.y)X-=x.y;
				else {printf("%lld\n",x.x);break;}
			}
		}
		if (opt==4)
		{
			split(l),split(r+1);int res=0;
			for (auto x:s)if (x.l>=l&&x.r<=r)res=(res+poww(x.v,X,Y)*(x.r-x.l+1))%Y;
			printf("%lld\n",res);
		}
//		cout<<opt<<' '<<l<<' '<<r<<' '<<X<<' '<<Y<<endl; 
//		puts("qwq");
//		for (auto x:s)cout<<x.l<<' '<<x.r<<' '<<x.v<<endl;
//		puts("qwq");
	}
	return 0;
}
/*
10 6 7 9
*/