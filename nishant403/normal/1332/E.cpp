#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 998244353;
const int M = 998244353;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
   
    a%=MOD;
    
    if(a == 0) return 0;
    
    b%=(MOD-1);
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}


int add(int a, int b)
{
	int res = a + b;
	if(res >= M)
		return res - M;
	return res;
}

int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= M)
		return res % M;
	return res;
}

const int SZ = 2;

struct matrix
{
	int arr[SZ][SZ];

    matrix()
    {
      reset();   
    }
    
	void reset()
	{
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
                 arr[i][j] = 0;
	}

	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, int b)
{
	matrix res;
	res.makeiden();
	while(b)
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


void solve()
{
  int n,m,l,r;
    cin >> n >> m >> l >> r;
    
   l--;
    
   int even = (r/2) - (l/2);
   int odd = (r-l) - even;
    
  if(n%2 == 1 && m%2 == 1)
  {
      cout << mod_pow(r-l,(n*m));
      return;
  } 
     
  int res1 = mod_pow(even+odd,(n*m));
  int res2 = mod_pow(abs(even-odd),(n*m));
   
  int res = (res1 + res2)%MOD;
     
 res=(res*mod_pow(2,MOD-2))%MOD;
    
   cout << res;
    
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}