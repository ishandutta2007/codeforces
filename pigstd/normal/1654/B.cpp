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
int n,c[30];
char s[M];

signed main()
{
	WT
	{
		memset(c,0,sizeof(c));
		cin>>s+1;
		n=strlen(s+1);
		int p=1;
		for (int i=1;i<=n;i++)c[s[i]-'a']++;
		while(c[s[p]-'a']>1)c[s[p]-'a']--,p++;
		for (int i=p;i<=n;i++)cout<<s[i];puts("");
	}
	return 0;
}