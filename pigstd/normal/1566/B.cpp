//AFO countdown:???
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

const int M=1e5+10;
int n,a[M];
string s;

signed main()
{
	WT{
		cin>>s;
		int cnt=0,n=s.size();
		for (int i=0;i<n;i++)
			a[i+1]=s[i]-'0';
		int l=-1,r=-1;
		for (int i=1;i<=n;i++)
			if (a[i]==0){l=i;break;}
		for (int i=n;i>=1;i--)
			if (a[i]==0){r=i;break;}
		if (l==-1){puts("0");continue;}
		int s[4];s[0]=s[1]=s[2]=0;
		for (int i=l;i<=r;i++)
			s[a[i]]=1;
		int ans=2;
		if (s[1]==0)ans=1;
		if (s[0]==0)ans=0;
		cout<<ans<<endl;
	}
	return 0;
}