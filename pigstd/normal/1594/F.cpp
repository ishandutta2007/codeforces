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

int work(int s,int k)
{
	int n1=s/k,s1=k-s%k,n2=s/k+1,s2=s%k;
	return (n1+1)/2*s1+(n2+1)/2*s2-(n1&1);
}

signed main()
{
	WT
	{
		int s=read(),n=read(),k=read();
		if (k==s){YES continue;}
		if (k>s){NO continue;}
		if (work(s,k)>=n)NO
		else YES
	}
	return 0;
}