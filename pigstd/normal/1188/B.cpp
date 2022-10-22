#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

int n,p,k,ans;
map<int,int>t;

signed main()
{
	n=read(),p=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();int w=x*x%p*x%p*x%p;
		w-=x*k%p;w+=p,w%=p;
//		cout<<w<<' ';
		ans-=t[w]*(t[w]-1)/2;t[w]++;
		ans+=t[w]*(t[w]-1)/2;
	}cout<<ans<<endl;
	return 0;
}