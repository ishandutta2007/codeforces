#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<ii>;
const ll MOD = 1000000007;
const int INF = 1000000000;
const double PI = 3.14159265358979323846;
#define fi first
#define se second
#define pb push_back
#define sz(cont) static_cast<int>((cont).size())
#define all(cont) (cont).begin(),(cont).end()
#define REP(n) for(int i=0, _i=(n); i<_i; ++i)
#define FOR(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define DWN(i,n) for(int i=(n); i>=0; --i)
#define FORI(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
int n, p;
int l = 26;
bool k[27];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        char a;
        cin >> a;
        string s;
        cin >> s;
        if (l == 1 && a != '.') {
            p++;
        }
        else {
            if (a == '.' || a=='?') {
                for (int j = 0; j < s.size(); j++) {
                    k[s[j] - 'a' + 1] = true;
                }
            }
            else {
                bool v[27];
                for (int j = 1; j <= 26; j++) {
                    v[j] = false;
                }
                for (int j = 0; j < s.size(); j++) {
                    v[s[j] - 'a' + 1] = true;
                }
                for (int i = 1; i <= 26; i++) {
                    if (!v[i]) {
                        k[i] = true;
                    }
                }
            }
        }
        l = 0;
        for (int j = 1; j<= 26; j++) {
            if (!k[j]) {
                l++;
               // cout << j << " ";
            }
        }
       // cout << endl;
    }
    cout << p << endl;
}