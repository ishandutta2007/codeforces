#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
#define f(i,n) for(int i=0;i<n;i++)

const int LN = 5;
const int M = 1e9+6;

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
        f(i,LN) f(j,LN) jt[i][j] = 0;
    }
    
    void makeiden()
    {
        reset();
        f(i,LN) jt[i][i] = 1;
    }
    matrix operator +(matrix &a)
    {
        matrix copy;
         copy.reset();   
        
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
    
	while(b)
	{
		if(b&1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

const int MOD = M + 1;

int powerr(int a,int b)
{
 int ans = 1;
    
    while(b)
    {
     if(b&1) ans=(ans*a)%MOD;   
     a=(a*a)%MOD;
     b>>=1;
    }
    return ans;
}

signed main()
{
 FAST;
  
 ll n,d,a,b,c;
    
 cin >> n >> a >> b >> c >> d;
    
 matrix mm;   
  
  f(i,5) f(j,5) mm.jt[i][j] = 0;
     
 mm.jt[0][0] = 1;   
 mm.jt[0][1] = 1;   
 mm.jt[0][2] = 1;   
 mm.jt[0][3] = 2;   
 mm.jt[0][4] = -2;   
 mm.jt[1][0] = 1;   
 mm.jt[2][1] = 1;   
 mm.jt[3][3] = 1;   
 mm.jt[3][4] = 1;   
 mm.jt[4][4] = 1;   
 
 matrix tt ;
    
 tt =  bin_pow(mm,n-3); 
     
 int aa = 0;   
     
 aa+=(2*tt.jt[0][3])%M;
 aa+=(tt.jt[0][4])%M;  
 aa= powerr(d,aa)%MOD;
    
//now for power of f1 = a 
    
 mm.jt[0][3]= 0;   
 mm.jt[0][4]= 0;    
 mm.jt[3][3] = 0;   
 mm.jt[3][4] = 0;   
 mm.jt[4][4] = 0;   
 
 matrix gh = bin_pow(mm,n-3);   
    
 int ofa = gh.jt[0][2];
 int ofb = gh.jt[0][1];   
 int ofc = gh.jt[0][0];   
    
 aa = (aa*powerr(a,ofa))%MOD;   

 aa = (aa*powerr(b,ofb))%MOD;   

 aa = (aa*powerr(c,ofc))%MOD;   

  cout <<aa;
}