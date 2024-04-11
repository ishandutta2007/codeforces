#include<bits/stdc++.h>
#define int long long
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

const int M=2e5+10;
int p[M];
vector<pii>ans;
multiset<int>now;

int getmax(multiset<int>&x){auto p=x.end();p--;return *p;}
int getmin(multiset<int>&x){return *x.begin();}
void del(multiset<int>&x,int y){x.erase(x.find(y));}

void work(int x,int y,int p=1){x*=p,y*=p;del(now,x),del(now,y),now.insert(x+y),now.insert(abs(x-y)),ans.pb(mp(x,y));}

void solve(int n,int lim,int p)
{
	if (n<=2)return;
	while(n*2<=lim)lim/=2;
	if (n==lim)n--;
//	cout<<n<<" "<<lim<<" "<<p<<"\n";
	for (int i=n;i>lim/2;i--)work(i,lim-i,p);
//	puts("qwq");
	solve(lim-n-1,lim/2,p),solve(n-lim/2,lim/2,p*2);
}

void work2(int lim)
{
//	puts("QWQ");
	int cnt=0;
	for (auto x:now)if (x!=lim)p[++cnt]=x;
	for (int i=2;i<=cnt;i++)
		if (p[i]==p[i-1]){work(p[i],p[i]),p[i]*=2,p[i-1]=0;break;}
	for (int i=1;i<=cnt;i++)
	{
		if (p[i]==0)continue;
		while(p[i]!=lim)work(p[i],0),work(p[i],p[i]),p[i]*=2;
	}
	work(0,lim); 
}

signed main()
{
	WT
	{
		int n=read();ans.clear();now.clear();
		if (n==2){puts("-1");continue;}
		for (int i=1;i<=n;i++)now.insert(i);
		int l=1;while(l<n)l<<=1;
		solve(n,l,1);work2(l);
		cout<<ans.size()<<'\n';
		for (auto x:ans)cout<<x.x<<' '<<x.y<<'\n';
	}
	return 0;
}