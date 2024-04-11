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

const int M=2e5+10;
int n,a[M];
map<int,int>t; 

signed main()
{
	WT
	{
		n=read(),t.clear();int sum=0;
		for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]++,sum+=a[i];
		if (sum*2%n!=0){puts("0");continue;}
		int k=sum*2/n;int res=0;
		for (int i=1;i<=n;i++)
		{
			t[a[i]]--;
			res+=t[k-a[i]];
			t[a[i]]++;
		}cout<<res/2<<endl;
	}
	return 0;
}