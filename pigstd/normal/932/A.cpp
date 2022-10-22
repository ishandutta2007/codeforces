#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
char ch[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge{int to,next;}e[M<<1];int cnt,head[M];
void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

signed main()
{
	cin>>ch;
	cout<<ch;
	for (int i=strlen(ch)-1;i>=0;i--)cout<<ch[i];
	return 0;
}