#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

int f;

void work(int a,int b,int c)
{
	if (a<b)swap(a,b);if (a<c)return;
	if (a==c||b==c||a-b==c){f=1;return;}
	if (b==1){f=1;return;}
	if (c%b==a%b){f=1;return;}
	work(a%b,b,c);
}

signed main()
{
	WT
	{
		int a=read(),b=read(),c=read();f=0;
		if (c%__gcd(a,b)||c>max(a,b)){NO continue;}
		int d=__gcd(a,b);a/=d,b/=d,c/=d;
		work(a,b,c);if (f)YES else NO
	}
	return 0;
}