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

const int M=1e4+10;
int n,a[M],p[M],x1,x2,k;

signed main()
{
	n=read(),k=read();
	for (int i=2;i<=n;i++)
	{
		cout<<"and 1 "<<i<<endl;cin>>x1;
		cout<<"or 1 "<<i<<endl;cin>>x2;
		a[i]=x1+x2;//cout<<a[i]<<' ';
	}//puts("");
	cout<<"and 2 3"<<endl;cin>>x1;
	cout<<"or 2 3"<<endl;cin>>x2;
	x1+=x2;p[1]=(a[3]+a[2]-x1)/2;//cout<<x1<<' '<<a[1]<<' '<<a[2]<<' '<<p[1]<<endl;
	for (int i=2;i<=n;i++)p[i]=a[i]-p[1];
//	for (int i=1;i<=n;i++)cout<<p[i]<<' ';
	sort(p+1,p+1+n);
	cout<<"finish "<<p[k]<<endl;
	return 0;
}