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

const int inf=1e9;
const int M=1e5+10;
int n,L,R,a[M];
map<int,int>t;

int check(int x)
{
	cout<<"? 1 "<<x<<endl;
	int y;cin>>y;
	return y==0;
}

int get(int x)
{
	x*=2;
	return sqrt(x)+1;
}

signed main()
{
	WT
	{
		n=read();cout<<"? 1 "<<n<<endl;
//		L=-1,R=-1;
		int x;cin>>x;
		int tl=1,tr=n,p=-1;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (check(Mid))p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
		cout<<"? "<<p+1<<" "<<n<<endl;int y;cin>>y;
		int len=x-y+1,p2=len+p;
		cout<<"? "<<p2<<' '<<n<<endl;cin>>y;
		len=get(y);int p3=p2+len-1;
		cout<<"! "<<p<<' '<<p2<<' '<<p3<<endl;
	}
	return 0;
}