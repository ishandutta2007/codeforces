#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
const int MAXN = 2e4 +10 ;
 
int mod_add(int a, int b) 
{
    int sum = a + b;
    return sum >= M ? sum - M : sum;
}
 
int mod_sub(int a, int b) 
{
    int diff = a - b;
    return diff < 0 ? diff + M : diff;
}
 
int mod_mul(int a, int b) 
{
    return ((long long)a*b)%M;
}
 
int mod_pow(int a, int p) 
{
    int result = 1;
 
    while (p > 0) 
    {
        if (p & 1) result = mod_mul(result, a);
        a = mod_mul(a, a);
        p >>= 1;
    }
 
    return result;
}

vector<pair<int,int>> reverse_it[16];

void prepare_reorder()
{
    for(int gl=1,n=2;gl<=15;gl++,n<<=1)
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

vector<int> roots = {0, 1};
int max_size = 8388608;
int root = 31;

void prepare_roots() 
{
   roots.resize((1<<15));
    
   for(int length=1;length<15;length++)
   {
    int z = mod_pow(root, max_size >> (length + 1));

    for (int i = 1 << (length - 1); i < 1 << length; i++) 
    {
        roots[2 * i] = roots[i];
        roots[2 * i + 1] = mod_mul(roots[i], z);
    }
 
   }
    
}

int round_up_power_two(int n) 
{ 
    while (n & (n - 1))
        n = (n | (n - 1)) + 1;

    return n;
}

// Given n (a power of two), finds k such that n == 1 << k.
int get_length(int n) 
{
    return __builtin_ctz(n);
}

namespace NTT 
{ 
 
    void fft_iterative(int N, vector<int> &values) {
       
        for(auto x : reverse_it[get_length(N)])
            swap(values[x.first],values[x.second]);
        
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    int even = values[start + i];
                    int odd = mod_mul(values[start + n + i], roots[n + i]);
                    values[start + n + i] = mod_sub(even, odd);
                    values[start + i] = mod_add(even, odd);
                }
    }
 
    const int FFT_CUTOFF = 170;
 
    vector<int> mod_multiply(vector<int> left, vector<int> right) 
    {
        int n = left.size();
        int m = right.size();
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) M*M;
            vector<uint64_t> result(n + m - 1);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= M;
                }
 
            for (int i = 0; i < (int) result.size(); i++)
                if (result[i] >= (uint64_t) M)
                    result[i] %= M;
 
            return vector<int>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        fft_iterative(N, left);
        fft_iterative(N, right);
 
        int inv_N = mod_pow(N,M-2);
 
        for (int i = 0; i < N; i++)
            left[i] = mod_mul(mod_mul(left[i], right[i]), inv_N);
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
 
        return left;
    }
};
 
vector<int> final;

vector<int> go(int l, int r)
{
	int ln = r-l;
    
    if (r - l == 1)
    {
        vector<int> ret = {1,final[l]};
		return ret;
	}

	int mid = l + (round_up_power_two(r-l+1)>>1)-1;
    
	vector<int> resL = go(l, mid);
	vector<int> resR = go(mid, r);
	vector<int> res = NTT::mod_multiply(resL, resR);
    
	return res;
}

void solve()
{
    int n,k;
    
    cin >> n >> k;
    
    int a[n];
    
    final.resize(n);
 
    for(int i=0;i<n;i++) cin >> a[i];
    
    int t,qq,q,R,L,d,i;
    
    cin >> qq;
    
    while(qq--)
    {
        cin >> t;
        
        for(int i=0;i<n;i++) final[i] = a[i];
        
        if(t==1)
        {
          cin >> q >> i >> d;   
          final[i-1] = d;  
        }
        else
        {
          cin >> q >> L >> R >> d;
          for(int i=L;i<=R;i++) final[i-1]=mod_add(final[i-1],d);  
        }
        
        for(int i=0;i<n;i++) final[i] = mod_sub(q,final[i]);
        
        auto v = go(0,n);
        
        cout << v[k] << '\n';
    }
}

signed main()
{
    prepare_roots();
    prepare_reorder();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}