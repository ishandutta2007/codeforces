#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define MP make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for( i=a;i<=b;++i)
#define NFOR(i,a,b) for( i=a;i>=b;--i)

double a[18][18];
double memo[1<<18];
int n;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n;
    
    register int i,j,mask;
    FOR(i,0,n-1)
    FOR(j,0,n-1)
    cin>>a[i][j];
    int x;
    memo[(1<<n)-1]=1;
    NFOR(mask,(1<<n)-2,1)
    {
    	x= __builtin_popcount(mask);
	FOR(i,0,n-1)
	{
		if(mask&(1<<i))
		FOR(j,i+1,n-1)
		{
			
				if(mask&(1<<j))continue;	
				memo[mask]+=2.0*memo[mask|(1<<j)]/((x)*(x+1))*a[i][j];	
		}
		
			else
			{
				FOR(j,i+1,n-1)
				if(mask&(1<<j))
				{
					memo[mask]+=2.0*memo[mask|(1<<i)]/((x)*(x+1))*(a[j][i]);
				}
			}
			
		}
	}

    
    FOR(i,0,n-1)
    cout<<fixed<<memo[1<<i]<<" ";
    
	return 0;
}