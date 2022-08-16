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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
    
vector<int> multiply(vector<int> const& a, vector<int> const& b) 
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

const int N = 5e5 + 100;
int res[N];

void solve()
{
   for(int i=0;i<N;i++) res[i] = -1;
    
  int n,x,y;
    cin >> n >> x >> y;
    
    vi a(n);
    cin >> a[0];
    f(i,n) cin >> a[i];
    
    vi end(x+1);
    vi start(x+1);
    
    f(i,n) end[a[i]] = 1;
    f(i,n-1) start[x - a[i]] = 1;
    start[x] = 1;
    
    auto go = multiply(start,end);
    
    for(int i=x+1;i<=x+x;i++)
    {
        if(go[i] == 0) continue;
        int len = y + i - x;
        
        res[len] = len + len;
    }
 
    for(int i=1;i<N;i++)
        for(int j=i+i;j<N;j+=i) res[j] = max(res[i],res[j]);
    
    int q;
    cin >> q;
    
    while(q--)
    {
        cin >> x; 
        cout << res[x/2] << ' ';
    }
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}