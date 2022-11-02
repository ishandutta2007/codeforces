#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int n, k;

vector<int> get_xor(int n){
    vector<int> a;
    while(n > 0){
        a.pb(n % k);
        n /= k;
    }
    return a;
}

int make_xor(vector<int> a){
    int now = 1, sum = 0;
    for (auto to : a){
        sum += to * now;
        now *= k;
    }
    return sum;
}

int xorr(int a, int b){
    auto aa = get_xor(a), bb = get_xor(b);
    if (aa.size() < bb.size()) swap(aa, bb);
    for (int i = 0; i < bb.size(); i++){
        aa[i] = (aa[i] + bb[i]) % k;
    }
    return make_xor(aa);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int xr = 0;
        for (int i = 0; i < n; i++){
            int val = xorr(xr, i);
            cout << val << endl;
            int f;
            cin >> f;
            if (!f) {
                xr = xorr(xr, val);
                continue;
            }
            else break;
        }
    }
    return 0;
}