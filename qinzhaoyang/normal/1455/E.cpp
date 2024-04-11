#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5; 
int t,x[N],y[N],a[N],b[N],p[N],A,X[N],Y[N];
void C(int d)
{
	for(int i=1;i<=4;i++)
		X[i]=x[i],Y[i]=y[i];
	X[2]-=d,X[4]-=d,Y[3]-=d,Y[4]-=d;
	sort(X+1,X+5),sort(Y+1,Y+5);
	A=min(A,X[4]+X[3]-X[2]-X[1]+Y[4]+Y[3]-Y[2]-Y[1]);
}
signed main()
{
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=4;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<=4;i++)
			p[i]=i;
		A=1e18;
		do
		{
			for(int i=1;i<=4;i++)
				x[i]=a[p[i]],y[i]=b[p[i]];
			C(x[2]-x[1]),C(x[2]-x[3]),C(x[4]-x[1]),C(x[4]-x[3]);
			C(y[3]-y[1]),C(y[3]-y[2]),C(y[4]-y[1]),C(y[4]-y[2]);
		}while(next_permutation(p+1,p+5));
		cout<<A<<'\n';
	}
	return 0;
}