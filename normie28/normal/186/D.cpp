#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct req { long long l; long long r; long long a; };
int n, m, k, cnt, i, j, aa, b = 0, c[500001], t[501][501],from500[501],used[500], even=0,odd=0;
vector<int> gt[500001],f; 
vector<int> s;
int main()
{
//	#define a a[i]
double a,b,c,sum,s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>a>>b>>c;
	sum=a+b+c;
	if (sum==0) cout<<0<<' '<<0<<' '<<s;
	else cout<<fixed<<setprecision(13)<<a/sum*s<<' '<<b/sum*s<<' '<<c/sum*s;
	
}