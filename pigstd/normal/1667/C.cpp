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

signed main()
{
	int n=read();
	if (n==1)return puts("1"),puts("1 1"),0;
	int k=(n-2)/3*3+2;
	cout<<n-k+(k/3*2)+1<<'\n';
	int x=(k/3*2)+1;
	for (int i=1;i<=x;i++)
	{
		int tmp=2*i-1; 
		if (tmp>x)tmp-=x;
		cout<<i<<' '<<tmp<<'\n';
	}
	if (n-k==2)cout<<n<<' '<<n<<'\n',cout<<n-1<<' '<<n-1<<'\n';
	else if (n-k==1)cout<<n<<' '<<n<<"\n";
	return 0;
}