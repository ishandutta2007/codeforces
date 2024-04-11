#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const double PI = acos(-1);
typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
 
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
 
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
 
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = int (fa[i].real() + 0.5);
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, k;
    cin >> n >> k;
    vector<vector<int>> pow(10);
    
    pow[0].resize(1001);

    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        pow[0][v] = 1;
    }
 
    for(int i = 1;i < 10;i++) {
        multiply(pow[i - 1], pow[i - 1], pow[i]); 
        for(int &j : pow[i])
            if (j != 0) j = 1;
    }
 
    vector<int> res = {1};
 
    for(int i = 0;i < 10;i++) {
        if ((k & (1 << i))) {
            multiply(res, pow[i], res);
            for(int &j : res)
                if (j != 0) j = 1;
        }
    }
 
    for(int i = 0;i < sz(res);i++) {
        if (res[i] != 0) cout << i << " ";
    }
}