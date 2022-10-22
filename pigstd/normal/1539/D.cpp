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
int n,ans;
struct node
{
	int a,b;
}a[M];

bool cmp(node a,node b){return a.b<b.b;}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i].a=read(),a[i].b=read();
	sort(a+1,a+1+n,cmp);
	int l=1,r=n,cnt=0;
	while(l<=r)
	{
		if (l==r)
		{
			if (cnt>=a[l].b)ans+=a[l].a;
			else if (cnt+a[l].a>a[l].b)
				ans+=a[l].a+a[l].b-cnt;
			else ans+=a[l].a*2;
			break;
		}
		if (a[l].b<=cnt)
			cnt+=a[l].a,ans+=a[l].a,l++;
		else
		{
			if (a[r].a+cnt>a[l].b)
				ans+=2*(a[l].b-cnt),a[r].a-=a[l].b-cnt,cnt=a[l].b;
			else ans+=2*a[r].a,cnt+=a[r].a,r--;
		}
	}cout<<ans<<endl;
	return 0;
}