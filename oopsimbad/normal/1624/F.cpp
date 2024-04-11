#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
    int n; cin >> n;
    int l = 1, h = n-1;
    vector<int> moves;
    while(l != h) {
        int m = (l+h+1)/2;

        int add = (m/n+1)*n - m;

        cout << "+ " << add << endl;

        int v; cin >> v;
        l = max(l+add, v*n);
        h = min(h+add, v*n+n-1);
    }
    cout << "! " << l << endl;
}