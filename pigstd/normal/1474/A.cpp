#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5;
int T,len;
string s;

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
	cin>>T;
	while(T--)
	{
		cin>>len>>s;int la=-1;
		for (int i=1;i<=len;i++)
			if (s[i-1]-'0'+1!=la)cout<<"1",la=s[i-1]-'0'+1;
			else cout<<"0",la=s[i-1]-'0';
			
		puts("");
	}
	return 0;
}