#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

mt19937 rnd(time(0));
int ask(int l1,int r1,int l2,int r2)
{
	printf("? %d %d\n",r1-l1+1,r2-l2+1);
	for (int i=l1;i<=r1;i++) print(i," \n"[i==r1]);
	for (int i=l2;i<=r2;i++) print(i," \n"[i==r2]);
	fflush(stdout);
	string s;
	cin>>s;
	if (s=="FIRST") return 1;
	if (s=="SECOND") return 2;
	if (s=="EQUAL") return 0;
	exit(0);
}
int ask(int x,int y){return ask(x,x,y,y);}
void answer(int x){printf("! %d\n",x),fflush(stdout);}
void work()
{
	int n=read(),k=read();
	vector<int>p; p.reserve(n);
	for (int i=2;i<=n;i++) p.push_back(i);
	shuffle(p.begin(),p.end(),rnd);
	for (int i=0;i<(int)p.size()&&i<20;i++) if (ask(1,p[i])==2) return answer(1);
	int l=0,r=0;
	for (int i=1;i<=n;i+=i)
	if (i+i>=n||ask(1,i,i+1,i+i)){l=i+1,r=min(i+i,n);break;}
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (ask(1,mid-l+1,l,mid)) r=mid-1;
							 else l=mid+1;
	}
	answer(l);
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}