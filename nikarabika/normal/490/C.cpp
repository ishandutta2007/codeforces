#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

ll t[1000000 + 100];

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    const int n = s.size();
    int A[n];
    ll a, b;
    cin >> a >> b;
    t[n-1] = 1;
    for(int i = n - 2; i > 0; i--){
        t[i] = t[i + 1] * 10;
        t[i] %= b;
        if(t[i] == 0)
            break;
    }
    ll r1 = 0, r2 = 0;
    rep(i, s.size())
        A[i] = s[i] - 48;
    r1 = A[0] % a;
    FOR(i, 1, n-1){
        r2 *= 10;
        r2 += A[i];
        r2 %= b;
    }
    FOR(i, 1, n-1){
        if(r1 == 0 && r2 == 0){
            while(A[i] == 0)
                i++;
            if(i == n){
                cout << "NO\n";
                return 0;
            }
            cout << "YES" << endl;
            rep(j, i)
                cout << s[j];
            cout << endl;
            FOR(j, i, n-1)
                cout << s[j];
            cout << endl;
            return 0;
        }
        r1 *= 10;
        r1 += A[i];
        r1 %= a;
        r2 -= A[i] * t[i];
        r2 = ((r2 % b) + b) % b;
    }
    cout << "NO\n";
    return 0;
}