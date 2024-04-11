#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=105;
int T,n;
string s1,s2,s3,s4;

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
	cin>>T;
	while(T--)
	{
		cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		int LCM=lcm(len1,len2);
		s3=s4="";
		for (int i=1;i<=LCM/len1;i++)s3+=s1;
		for (int i=1;i<=LCM/len2;i++)s4+=s2;
		if (s3==s4)cout<<s3<<endl;
		else puts("-1");
	}return 0;
}