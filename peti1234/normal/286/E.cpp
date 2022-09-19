#include <bits/stdc++.h>

using namespace std;


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
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
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




int n, m;
vector<int> a, b, ans;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    a.resize(m+1);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        a[x]=1;
    }
    b=multiply(a, a);
    for (int i=1; i<=m; i++) {
        if (a[i] && !b[i]) {
            ans.push_back(i);
        }
        if (b[i] && !a[i]) {
            baj=1;
        }
    }
    if (baj) {
        cout << "NO\n" << "\n";
    } else {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (int x:ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}