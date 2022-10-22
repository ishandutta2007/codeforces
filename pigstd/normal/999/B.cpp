#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int n;char c[1000];

signed main()
{
	cin>>n>>c+1;
	for (int i=1;i<=n;i++)
	{
		if (n%i!=0)continue;
		for (int j=1;j<=i/2;j++)swap(c[j],c[i-j+1]);
	}
	cout<<c+1;
	return 0;
}