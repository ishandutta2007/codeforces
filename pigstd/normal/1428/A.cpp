#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	cin>>T;
	while(T--)
	{
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		if (x1==x2&&y1==y2){puts("0");continue;} 
		int ans=abs(x1-x2)+abs(y1-y2)-1;
		if (x1==x2||y1==y2)
			ans=ans+1;
		else
			ans=ans+3;
		cout<<ans<<endl;
	}
	return 0;
}

//stO sjy Orz
//rp++