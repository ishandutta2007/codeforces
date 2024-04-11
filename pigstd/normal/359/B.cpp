#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int n,a[M],k;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	n=read(),k=read();
	for (int i=1;i<=2*n;i++)a[i]=i;
	for (int i=1;i<=k;i++)swap(a[i*2],a[i*2-1]);
	for (int i=1;i<=2*n;i++)cout<<a[i]<<' ';
	return 0;
}