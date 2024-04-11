#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int T,n,k,a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void f()
{
	int maxn=-1e9-10;
	for (int i=1;i<=n;i++)maxn=max(maxn,a[i]);
	for (int i=1;i<=n;i++)a[i]=maxn-a[i];
	return;
}

int main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();
		for (int i=1;i<=n;i++)a[i]=read();
		if (k&1)f();
		else f(),f();
		for (int i=1;i<=n;i++)cout<<a[i]<<' ';
		puts("");
	}
	return 0;
}