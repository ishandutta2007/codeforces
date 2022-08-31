//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT

#pragma optimize("", off)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:36777216")
#include<bits/stdc++.h>
using namespace std;

#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define pi acos(-1)
#define bp __builtin_popcountll
#define ll long long int
#define ld long double
#define pii pair<ll , ll>
#define For(i,a,b) for(ll i=a;i<b;i++)
#define Fori(i,a,b,p) for(ll i=a;i<b;i+=p)
#define Ror(i,a,b) for(ll i=a;i>b;i--)
#define Rori(i,a,b,p) for(ll i=a;i>b;i-=p)

#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 

#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))


const ll LN = 100;
const ll M = 1e9 + 7;
vector<ll> t1(LN,0) , t2(LN,0);

ll add(ll a,ll b)
{
    ll x = a + b;
    if(x >= M)
        x -= M;
    return x;
}

ll mult(ll a,ll b)
{
    return (a % M * b %M)%M;
}
struct matrix
{
    ll jt[LN][LN];
    
    void reset()
    {
        FILL(jt,0);
    }
    void makeiden()
    {
        reset();
        For(i,0,LN)
            jt[i][i] = 1;
    }
    matrix operator +(matrix &a)
    {
        matrix copy;
        For(i,0,LN)
            For(j,0,LN)
                copy.jt[i][j] = add(jt[i][j],a.jt[i][j]);
        return copy;
    }
    matrix operator *(matrix &a)
    {
        matrix copy;
        copy.reset();
        For(i,0,LN)
            For(j,0,LN)
                For(k,0,LN)
                copy.jt[i][j] = add(copy.jt[i][j],mult(jt[i][k] , a.jt[k][j]));
        return copy;
    }
};

matrix bin_pow(matrix a, ll b)
{
	matrix res;
	res.makeiden();
	while(b > 0)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll work(matrix a,int n)
{
    ll ans = 0;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) 
           ans=(ans+a.jt[i][j])%M;
        
        return ans;
}

int main()
{
    FAST;
    int i,j;
 ll n,k;
    cin >> n >> k;
    
ll a[n];
    
    for(i=0;i<n;i++) cin >> a[i];
    
    matrix A;
    
    A.reset();
    
    for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)   
     {
      if( (bp(a[i]^a[j])%3)== 0) A.jt[i][j]=1;  
     }  
    }
    
    matrix temp = bin_pow(A,k-1);
    
    cout << work(temp,n);
    
}