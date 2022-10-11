// Not my code
// https://codeforces.com/contest/632/submission/94569504

//
//
#pragma GCC optimization ("O3")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;
 
using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;
 
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
 
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        w *= wn;
    }
    if (invert)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] /= 2;
        }
    }
}
 
vector<int> mul(vector<int> const& a, vector<int> const& b)
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
 
    vector<int> result(a.size() + b.size() - 1);
    for (int i = 0; i < result.size(); i++)
        result[i] = min((int)round(fa[i].real()), 1);
    return result;
}
 
vector<int> pwr(vector<int>& a, ll p)
{
    vector<int> r = {1};
    while (p > 0)
    {
        if (p % 2)
            r = mul(r, a);
        a = mul(a, a);
        p /= 2;
    }
    return r;
}
 
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(1001);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    vector<int> sol = pwr(a, k);
    for (int i = 1; i < sol.size(); ++i)
        if (sol[i] > 0)
            cout << i << ' ';
}