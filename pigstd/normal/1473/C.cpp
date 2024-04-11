#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int T,n,k;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

int lcm(int a,int b)
{
	return a*b/__gcd(a,b);
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();
		int f=n-(n-k)*2;
		for (int i=1;i<f;i++)cout<<i<<' ';
		for (int i=k;i>=f;i--)cout<<i<<' ';
		puts("");
	}
	return 0;
}