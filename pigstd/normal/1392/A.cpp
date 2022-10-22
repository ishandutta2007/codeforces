#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,n,a;

int main()
{
	T=read();
	while(T--)
	{
		n=read();a=read();bool flag=1;
		for (int i=2;i<=n;i++)
			if (read()!=a)flag=0;
		if (flag)cout<<n<<endl;
		else puts("1");
	}
	return 0;
}