#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),k=read();
	cout<<k*(6*n-1)<<endl;
	for (int i=1;i<=n;i++)
		cout<<(6*i-4)*k<<' '<<(6*i-5)*k<<' '<<(6*i-3)*k<<' '<<(6*i-1)*k<<endl;
	return 0;
}