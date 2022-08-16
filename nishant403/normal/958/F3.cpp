#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ld long double

const int MOD = 1009;

using cd = complex<double>;
const double PI = acos(-1);

const int LN = 18;
const int N = (1 << LN);
cd W[N], invW[N];

vector<pair<int,int>> reverse_it[LN+1];

void prepare_reorder()
{
    for(int gl=1,n=2;gl<=LN;gl++,n<<=1)
    {
      vector<int> bit_reverse;
        
      bit_reverse.assign(n, 0);
 
      for (int i = 0; i < n; i++)
      {
      bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (gl - 1)); 
      if(i < bit_reverse[i]) reverse_it[gl].push_back({i,bit_reverse[i]});
      }
          
    }
}

void precompute_powers()
{
	for (int i = 0; i < N / 2; i++)
	{
		double ang = (2*PI*i)/N;
		ld _cos = cos(ang), _sin = sin(ang);
		W[i] = cd(_cos,_sin);
		invW[i] = cd(_cos,-_sin);
	}
}

// Given n (a power of two), finds k such that n == 1 << k.
int get_length(int n) 
{
    return __builtin_ctz(n);
}

void fft(vector<cd> & a, bool invert) {
    
    int n = a.size();

    for(auto x : reverse_it[get_length(n)])
            swap(a[x.F],a[x.S]);
    
    for (int len = 2; len <= n; len <<= 1) 
    for (int i = 0; i < n; i += len)   
    for (int ind = 0,j = 0; j < len / 2; j++,ind+=(N/len)) 
    {
     cd u = a[i+j], v = a[i+j+len/2] * (invert ?  invW[ind] : W[ind]);
     a[i+j] = u + v;
     a[i+j+len/2] = u - v; 
    }
      
    if (invert) for (cd & x : a)  x /= n;
}
    
vector<int> arr;
int k;

vector<int> multiply(vector<int> const& a, vector<int> const& b) 
{
    int flag = 1;
    
    for(auto x : a)
        if(x!=1) 
    {
        flag = 0;
        break;
    }
    
    for(auto x : b)
        if(x!=1) 
        {
            flag = 0;
            break;
        }
    
    if(flag == 1)
    {
        int nn = a.size(),mm = b.size();
        vector<int> res(nn+mm-1);
       
        int val = 0;
        
        f(i,nn+mm-1)
        {
            if(i<min(nn,mm)) val++;
            else if(i>=nn+mm-min(nn,mm)) val--;
            
            res[i] = val;     
        }
        
        return res;  
    }
    
    if(min(a.size(),b.size()) < 250)
    {
    vector<int> result((int)a.size()+(int)b.size()-1);
        
    f(i,a.size()) f(j,b.size())
    {
     result[i + j] +=a[i]*b[j];
     if(result[i+j] > MOD) result[i+j]%=MOD;
    }
     
     return result;  
    }
 
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

     fft(fa, false);  fft(fb, false);
      f(i,n)  fa[i] *= fb[i];
     fft(fa, true);

    n = min(n,k+1);
    
    vector<int> result(n);
    f(i,n) result[i] = (round(fa[i].real()));
    f(i,n) if(result[i] > MOD) result[i] %= MOD;
    
    return result;
}

vector<int> go(int l,int r)
{
    if(l == r)
    {
        vector<int> poly(arr[l],1); 
        return poly;
    }
    
    int mid = (l+r)/2;
 
    return multiply(go(l,mid),go(mid+1,r));
}

void solve()
{
    auto v = go(0,(int)arr.size()-1);   
    cout << v[k];
}

signed main()
{
fast;    
precompute_powers();
prepare_reorder();
    
int n,m,x;
cin >> n >> m >> k;
   
vector<int> cnt(m+1,0);
    
f(i,n)
{
    cin >> x;
    cnt[x]++;
}
    
f(i,m+1) if(cnt[i] > 0) arr.pb(min(cnt[i],k)+1);
    
solve();
}