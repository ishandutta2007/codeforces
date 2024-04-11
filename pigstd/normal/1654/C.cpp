#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,a[M];
map<int,int>t;

signed main()
{
	WT
	{
		n=read();int sum=0;t.clear();
		for (int i=1;i<=n;i++)t[a[i]=read()]++,sum+=a[i];
		sort(a+1,a+1+n);
		int p1=1,p2=0,F=1;
		while(sum!=1)
		{
			int t1=min(p1,t[sum]);p1-=t1,t[sum]-=t1;
			int t2=min(p2,t[sum+1]);p2-=t2,t[sum+1]-=t2;
			if (sum&1)p2=p2*2+p1;
			else p1=p1*2+p2;sum/=2;
		}
		/*
		1:p1 2:p2
		*/
		int tmp=min(p2,t[2]);
		p2-=tmp;t[2]-=tmp;
		p1+=2*p2;p2=0;
		if (p1==t[1])YES
		else NO
	}
	return 0;
}