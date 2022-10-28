#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);srand(time(0))
#define pb push_back
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
const int N = 5e5+10;

int a[N],l[N],r[N];
int main()
{
    boost;
	int n,m,p;cin>>n>>m>>p;
	string s,t;
	cin>>s>>t;
	a[0]=0;
	FOR(i,1,n)a[i]=a[i-1]+(s[i-1]=='('?1:-1),l[i]=i-1,r[i]=i+1;
	FOR(i,0,m-1)
	{
		if(t[i]=='L')p=l[p];
		else if(t[i]=='R')p=r[p];
		else
		{
			
			if(s[p-1]==')')
			{
				int x;
				for(x=p;x>=1;x=l[x])
				if(a[x-1]==a[p])break;
				p=x;
			}
			
			int x;
			for(x=p;x<=n;x=r[x])
			{
				s[x-1]=' ';
				if(a[x]==a[p-1])break;
			}
			
			int t=r[x]<=n?r[x]:l[p];
			r[l[p]]=r[x];
			l[r[x]]=l[p];
			p=t;
		}
	}
	FOR(i,0,n-1)
	{
		if(s[i]!=' ')
		cout<<s[i];
	}
	return 0;
}