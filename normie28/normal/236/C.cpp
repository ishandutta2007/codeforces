#include<bits/stdc++.h>
using namespace std;
 
#define si(n) cin>>n
#define MAX 100005
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n" 
#define max(a,b) ((a>b)?a:b)
 
int col[MAX],val[MAX],a,b,n,q;
long long __lcm(long long a, long long b) {return a*b/__gcd(a,b);}
long long lcmm(long long a,long long b,long long c)
{
	return __lcm(a,__lcm(b,c));
}
 
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    if (n==1) cout<<1; else if (n==2) cout<<2; else if (n==3) cout<<6;
    else cout<<max(max(lcmm(n,n-1,n-2),lcmm(n-3,n-1,n-2)),max(lcmm(n,n-1,n-3),lcmm(n-3,n,n-2)));
}