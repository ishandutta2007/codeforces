#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int s[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

int main(){
    ios_base::sync_with_stdio(false);
    char c;
    int a, b;
    cin >> c;
    a = c - 48;
    cin >> c;
    b = c - 48;
    int c1 = 0, c2 = 0;
    rep(i, 10){
        bool t[2] = {true, true};
        rep(j, 7){
            if((s[i] & (1 << j)) == 0 && (s[a] & (1 << j)) != 0)
                t[0] = false;
            if((s[i] & (1 << j)) == 0 && (s[b] & (1 << j)) != 0)
                t[1] = false;
        }
        if(t[0])
            c1 ++;
        if(t[1])
            c2 ++;
    }
    cout << c1 * c2 << endl;
    return 0;
}