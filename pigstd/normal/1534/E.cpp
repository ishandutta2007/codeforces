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

const int M=510; 
int n,k,a[M],res,cnt,x[M],y[M];
priority_queue<pair<int,int> >q;

signed main()
{
	n=read(),k=read();
	if (n%2==1&&k%2==0)return puts("-1"),0;
	for (int i=1;i<=n;i++)a[i]=1,cnt++;
	while(cnt%k!=0)
	{
		for (int i=1;i<=n&&(cnt%k!=0||a[1]>cnt/k);i++)
			a[i]+=2,cnt+=2;
	}
	for (int i=1;i<=n;i++)q.push(mp(a[i],i));
	while(!q.empty())
	{
		for (int i=1;i<=k;i++)
			x[i]=q.top().x,y[i]=q.top().y,q.pop();
		cout<<"?";
		for (int i=1;i<=k;i++)
			cout<<' '<<y[i];cout<<endl;
		int l=read();res^=l;
		for (int i=1;i<=k;i++)
			if (x[i]!=1)q.push(mp(x[i]-1,y[i]));
	}cout<<"! "<<res<<endl;
	return 0;
}