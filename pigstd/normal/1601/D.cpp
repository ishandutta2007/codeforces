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

const int M=5e5+10;
int n,d,res;
struct node
{
	int a,s;
}a[M];
bool cmp(node a,node b){return max(a.a,a.s)==max(b.a,b.s)?a.s<b.s:max(a.a,a.s)<max(b.a,b.s);}

signed main()
{
	n=read(),d=read();
	for (int i=1;i<=n;i++)a[i].s=read(),a[i].a=read();
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (a[i].s>=d)res++,d=max(d,a[i].a);
	cout<<res<<endl;
	return 0;
}