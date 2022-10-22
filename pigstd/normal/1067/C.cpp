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

signed main()
{
	int n=read();int x=n/3;
	if (x!=0)puts("0 0"),puts("0 1"),puts("0 -1");
	for (int i=1;i+1<x;i++)
		cout<<i*2-1<<' '<<0<<endl,
		cout<<i*2<<' '<<1<<endl,
		cout<<i*2<<' '<<-1<<endl;
	if (x>1)cout<<2*(x-1)-1<<' '<<0<<endl,cout<<2*(x-1)-1<<' '<<1<<endl,cout<<2*(x-1)-1<<' '<<-1<<endl;
	for (int i=x*3+1;i<=n;i++)cout<<2*(x-1)+(x==1?114514:0)<<' '<<x*3+2-i<<endl;
	return 0;
}