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

signed main()
{
	WT
	{
		int x=read(),y=read();
		int c1=read(),c2=read(),c3=read(),c4=read(),c5=read(),c6=read();
		c1=min(c1,c6+c2),c2=min(c2,c1+c3),c3=min(c3,c2+c4),c4=min(c4,c3+c5),c5=min(c5,c4+c6),c6=min(c6,c5+c1);
		if (x>=0&&y>=0)
			cout<<min(x,y)*c1+abs(x-y)*((x>y)?c6:c2)<<endl;
		else if (x<=0&&y>=0)
			cout<<c3*(-x)+y*c2<<endl;
		else if (x>=0&&y<=0)
			cout<<c6*x-c5*y<<endl;
		else cout<<min(-x,-y)*c4+abs(x-y)*((x<y)?c3:c5)<<endl;
	}
	return 0;
}