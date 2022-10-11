#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int modpow(int b, int e)
{
    int a = 1;
    
    while (e)
    {
        if (e & 1)
            a = 1LL * a * b % MOD;
        b = 1LL * b * b % MOD;
        e >>= 1;
    }
    
    return a;
}

const int root = modpow(3, 119);
const int root_1 = modpow(root, MOD - 2);
const int root_pw = 1 << 23;

struct poly
{
    int *arr;
    int deg;
    
    poly(int n = 0)
    {
        arr = new int[n];
        deg = n;
        for (int i = 0; i != n; ++i)
            arr[i] = 0;
    }
    
    int degree()
    {
        return deg;
    }
    
    int & operator [] (int i)
    {
        return arr[i];
    }
};

void fft(poly & a, bool invert, int n)
{
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % MOD);

        for (int i = 0; i < n; i += len)
        {
            int w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % MOD);
                a[i+j] = u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (int)(1LL * w * wlen % MOD);
            }
        }
    }

    if (invert)
    {
        int n_1 = modpow(n, MOD - 2);
        for (int i = 0; i != n; ++i)
            a[i] = (int)(1LL * a[i] * n_1 % MOD);
    }
}

void print(poly & a)
{
    for (int i = 0; i != a.degree(); ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

void mult(poly & a, poly & b, poly & c)
{
    int n = a.degree();
    
    fft(a, 0, n);
    fft(b, 0, n);
    
    for (int i = 0; i != n; ++i)
        c[i] = 1LL * a[i] * b[i] % MOD;
    
    fft(a, 1, n);
    fft(b, 1, n);
    fft(c, 1, n);
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    int r = 1;
    while (r < n)
        r <<= 1;
    
    int arr[n];
    for (int i = 0; i != n; ++i)
        cin >> arr[i];
    
    int q;
        
    poly polys[2 * r];
    for (int j = 0; j != r; ++j)
    {
        polys[r + j] = poly(4);
        polys[r + j][0] = 1;
    }
    for (int i = r - 1; i != 0; --i)
        polys[i] = poly(2 * polys[2 * i].degree());
    
    for (cin >> q; q--;)
    {
        int t;
        cin >> t;
        
        if (t == 1)
        {
            int qq, i, d;
            cin >> qq >> i >> d;
            for (int j = 0; j != n; ++j)
            {
                polys[r + j][0] = qq - arr[j];
                polys[r + j][1] = 1;
            }
            polys[r + i - 1][0] = qq - d;
        }
        else
        {
            int qq, l, rr, d;
            cin >> qq >> l >> rr >> d;
            for (int j = 0; j != n; ++j)
            {
                polys[r + j][0] = qq - arr[j];
                polys[r + j][1] = 1;
            }
            for (int i = l - 1; i != rr; ++i)
                polys[r + i][0] -= d;
        }
        for (int i = r; i != 2 * r; ++i)
            for (int j = 0; j != 2; ++j)
            {
                polys[i][j] %= MOD;
                polys[i][j] += MOD;
                polys[i][j] %= MOD;
            }
        
        for (int i = r - 1; i != 0; --i)
            mult(polys[2 * i], polys[2 * i + 1], polys[i]);
        
        cout << (polys[1][n - k] + MOD) % MOD << '\n';
    }
    
    return 0;
}