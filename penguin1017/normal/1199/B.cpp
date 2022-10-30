#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b-1;i>=a;i--)
#define N (int)1e5+9
#define eps 1e-9
using namespace std;
int main()
{
	long long H,L;
	cin>>H>>L;
	double ans;
	ans=0.5*(L*L-H*H)/H;
	printf("%.7lf",ans+eps);
}