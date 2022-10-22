#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
int a[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int ask(int l,int r)
{
	if (l==r) return l;
	cout << "? " << l << " " << r << endl;
	fflush(stdout);
	int res=read();
	return res;
}

int main()
{
	int n=read();
	int l=1,r=n;
	if (n==2)
	{
		int t=ask(l,r);
		if(t==l) cout << "! " << r << endl;
		else cout << "! " << l << endl;
		fflush(stdout);
		return 0;
	}
	int u=ask(l,r);
	while (3<=r-l+1)
	{
		int mid=(l+r)/2;
		int t;
		if (l<=u&&u<=r)
		{
			if (u<=mid) 
			{
				t=ask(l,mid);
				if (t==u) r=mid;
				else 
				{
					l=mid+1;
				}
			}
			else 
			{
				t=ask(mid,r);
				if (t==u) l=mid;
				else 
				{
					r=mid-1;
				}
			}	
		 } 
		else
		{
			if (u<l)
			{
				t=ask(1,mid);
				if (t==u) r=mid;
				else l=mid+1;
			}
			else
			{
				t=ask(mid,n);
				if (t==u) l=mid;
				else r=mid-1;
			}
		}
	}
	if (r-l+1==1) cout << "! " << l << endl;
	else 
	{
		int t=ask(l,r);
		if(t==l) cout << "! " << r << endl;
		else cout << "! " << l << endl;
	}
	fflush(stdout);
	return 0;
}
//.......x..........

// max(dp(nk),dp(n-nk)+1)
// 1 5 3 9 2 7 8 10 4 6

// 3 1 2