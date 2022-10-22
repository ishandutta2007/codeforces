#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

int a[5];

signed main()
{
	WT
	{
		for (int i=1;i<=4;i++)a[i]=read();
		int a1=max(a[1],a[2]),a2=max(a[3],a[4]);
		sort(a+1,a+5);
		if (a1>a2)swap(a1,a2);
		if (a1==a[3]&&a2==a[4])YES
		else NO
	}
	return 0;
}