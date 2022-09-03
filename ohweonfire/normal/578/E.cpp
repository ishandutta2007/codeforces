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

const int maxn=100111;
char s[maxn];int n,pre[maxn],nxt[maxn],last[maxn];

void visit(int x)
{
	if(!x)return;
	printf("%d ",x);
	visit(nxt[x]);
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	
	queue<int> ql,qr;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			if(!qr.empty())
			{
				nxt[qr.front()]=i;
				pre[i]=qr.front();
				qr.pop();
			}
			ql.push(i);
		}
		else
		{
			if(!ql.empty())
			{
				nxt[ql.front()]=i;
				pre[i]=ql.front();
				ql.pop();
			}
			qr.push(i);
		}
	}
	
	for(int i=n;i>=1;i--)
	{
		if(!nxt[i])last[i]=i;
		else last[i]=last[nxt[i]];
	}
	queue<int> LL,LR,RL,RR;
	
	int ans=-1;
	for(int i=1;i<=n;i++)if(!pre[i])
	{
		ans++;
		if(s[i]=='L'&&s[last[i]]=='L')LL.push(i);
		else if(s[i]=='L'&&s[last[i]]=='R')LR.push(i);
		else if(s[i]=='R'&&s[last[i]]=='L')RL.push(i);
		else if(s[i]=='R'&&s[last[i]]=='R')RR.push(i);
	}
	printendl(ans);
	if((int)LL.size()<(int)RR.size())
	{
		swap(LL,RR);
		swap(LR,RL);
	}
	if((int)LL.size())
	{
		while(!LR.empty())
		{
			visit(LR.front());
			LR.pop();
		}
		visit(LL.front());LL.pop();
		while(!RL.empty())
		{
			visit(RL.front());
			RL.pop();
		}
		while(!RR.empty())
		{
			visit(RR.front());RR.pop();
			if(!LL.empty())visit(LL.front());LL.pop();
		}
		return 0;
	}
	if(LR.empty()||RL.empty())
	{
		while(!LR.empty())
		{
			visit(LR.front());
			LR.pop();
		}
		while(!RL.empty())
		{
			visit(RL.front());
			RL.pop();
		}
		return 0;
	}
	int f1=LR.front(),f2=RL.front();LR.pop();RL.pop();
	if(f1<f2)
	{
		RR.push(nxt[f1]);
		nxt[f1]=f2;
		LL.push(f1);
	}
	else
	{
		LL.push(nxt[f2]);
		nxt[f2]=f1;
		RR.push(f2);
	}
	while(!LR.empty())
	{
		visit(LR.front());
		LR.pop();
	}
	visit(LL.front());LL.pop();
	while(!RL.empty())
	{
		visit(RL.front());
		RL.pop();
	}
	while(!RR.empty())
	{
		visit(RR.front());RR.pop();
		if(!LL.empty())visit(LL.front());LL.pop();
	}
	return 0;
}