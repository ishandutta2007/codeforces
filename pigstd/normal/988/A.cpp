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

const int M=110;
int n,k,a[M],t[M]; 

signed main()
{
	n=read(),k=read();int cnt=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (t[a[i]]==0)cnt++;
		t[a[i]]=i;
	}
	if (cnt<k){NO return 0;}
	else YES
	for (int i=1,p=0;i<=100&&p<k;i++)
		if (t[i])cout<<t[i]<<' ',p++;
	return 0;
}