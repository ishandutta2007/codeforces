#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7;
const int N = 305;

void run() {
    int n; string s;
    cin >> n >> s;
    char lst = 'z'+1;

    int id = n; 

    for (int i = 0; i < n; ++i) {
        if (s[i] < lst || (s[i] == lst && i != 1)) lst = s[i];
        else {
            id = i;
            break;
        }
    }
    for (int i = 0; i < id; ++i)
        cout << s[i];
    for (int i = id-1; i >= 0; --i)
        cout << s[i];
    cout << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}