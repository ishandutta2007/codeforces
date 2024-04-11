#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,d,k;

signed main()
{
	T=read();
	while(T--)
	{
		d=read(),k=read();bool flag=0;
		for (int i=0;i*i*2<=d*d;i+=k)
			if (i*i+(i+k)*(i+k)>d*d)flag=1;
		if (flag)puts("Utkarsh");
		else puts("Ashish");
	}
	return 0;
}