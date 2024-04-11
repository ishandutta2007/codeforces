#define mm(a) memset(a,0,sizeof(a));
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define Fopen freopen("1.in","r",stdin); freopen("m.out","w",stdout);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,b,a) for(int i=(b);i>=(a);i--)
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=5005;
const ll mod=1e9+7;
 
int n,m,k,i,j,x; long long sum;
multiset<int> unused,sold; 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	unused.insert(1e9+7);
	sold.insert(1e9+7);
	for (i=0;i<n;i++)
	{
	cin>>x;
	auto it1=unused.lower_bound(-1);
	auto it2=sold.lower_bound(-1);
	int min1=*it1;
	int min2=*it2;
//	cout<<min1<<' '<<min2<<endl;
	int min3=min(min1,min2);
	if (min3<x)
	{
		if (min3==min2) {sold.erase(it2); unused.insert(min3); sold.insert(x);}
		 else {unused.erase(it1); sold.insert(x); }
		sum+=x-min3;
	}
	else unused.insert(x);
	}
	cout<<sum;
}