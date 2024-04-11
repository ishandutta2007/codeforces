#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

signed main()
{
	int a=read(),b=read(),c=read();
	cout<<"First"<<endl;
	cout<<1000000000<<endl;
	int x;cin>>x;
	if (x==1)
	{
		a+=1e9;cout<<2*a-b-c<<endl;
		int y;cin>>y;
		if (y==2)
		{
			b=2*a-c;
			cout<<a-c<<endl;
		}
		else
		{
			c=2*a-b;
			cout<<a-b<<endl;
		}
	}
	else if (x==2)
	{
		b+=1e9;cout<<2*b-a-c<<endl;
		int y;cin>>y;
		if (y==1)
		{
			a=2*b-c;
			cout<<b-c<<endl;
		}
		else
		{
			c=2*b-a;
			cout<<b-a<<endl;
		}
		
	}
	else
	{
		c+=1e9;
		cout<<2*b-a-c<<endl;
		int y;cin>>y;
		if (y==1)
		{
			a=2*c-b;
			cout<<c-b<<endl;
		}
		else
		{
			b=2*c-a;
			cout<<c-a<<endl;
		}
	}
	return 0;
}
/*

*/