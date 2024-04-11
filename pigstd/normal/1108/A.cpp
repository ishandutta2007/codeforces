#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,l1,l2,r1,r2;

signed main()
{
	T=read();
	while(T--)
	{
		l1=read(),r1=read(),l2=read(),r2=read();
		if (l1!=l2)cout<<l1<<' '<<l2<<endl;
		else cout<<l1<<' '<<l2+1<<endl;
	}
	return 0;
}