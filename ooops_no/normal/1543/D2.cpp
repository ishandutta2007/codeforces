#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int n, k;

vector<int> get_xor(int b){
    vector<int> a;
    while(b > 0){
        a.pb(b % k);
        b /= k;
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
    while(aa.size() < bb.size()) aa.pb(0);
    for (int i = 0; i < bb.size(); i++){
        aa[i] = (aa[i] + bb[i]) % k;
    }
    return make_xor(aa);
}

int xorrr(int a, int b){
    auto aa = get_xor(a), bb = get_xor(b);
    while(aa.size() < bb.size()) aa.pb(0);
    for (int i = 0; i < bb.size(); i++){
        aa[i] = (aa[i] - bb[i] + k) % k;
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
        int now = 0;
        bool f;
        for (int i = 0; i < n; i++){
            int val = (i % 2 == 0 ? xorr(now, i) : xorrr(now, i));
            cout << val << endl;
            cin >> f;
            if (f){
                break;
            }
            now = xorrr(val, now);
        }
    }
    return 0;
}