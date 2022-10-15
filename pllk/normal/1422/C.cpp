#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;

// 1 0 7 10 07 17 107

int main() {
    string n;
    cin >> n;
    ll ac = 0;
    ll as = 0;
    ll bc = 0;
    ll bs = 0;
    ll x = 0;
    int g = 0;
    for (char c : n) {
        int d = c-'0';
        ll uac = 0, uas = 0;
        ll ubc = 0, ubs = 0;
        // vika silyy
        uac += ac;
        uas += 10*as+ac*d;
        // vika poistetaan aiempien kanssa
        uac += bc;
        uas += bs;
        ubc += bc;
        ubs += bs;
        // vika poistetaan yksinn
        if (g) {
            uac += 1;
            uas += x;
            ubc += 1;
            ubs += x;
        }
        // vika on ainoa silyv
        uac += 1;
        uas += d;
        ac = uac%M;
        as = uas%M;
        bc = ubc%M;
        bs = ubs%M;
        x = (x*10+d)%M;
        g = 1;
    }
    ll f = 1;
    int k = n.size();
    for (int i = k-1; i >= 0; i--) {
        as -= (n[i]-'0')*f;
        as %= M;
        f = f*10%M;
    }
    as = (as%M+M)%M;
    cout << as << "\n";
}