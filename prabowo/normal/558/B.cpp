#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi 3.1415926535897932384626433

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector <int> vi;
typedef vector <pii> vii;

int n;
pipii angka[1000002];

int main() {
    scanf("%d", &n);
    for (int i=0; i<1000001; i++) angka[i].se.fi = n, angka[i].se.se = 1;

    int a;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        angka[a].fi++;
        angka[a].se.fi = min(angka[a].se.fi, i+1);
        angka[a].se.se = max(angka[a].se.se, i+1);
    }

    int mini = 0;
    pii ans = mp(0, 0);
    for (int i=1; i<=1000000; i++) {
        if (mini < angka[i].fi) {
            mini = angka[i].fi;
            ans = angka[i].se;
        } else if (mini == angka[i].fi) {
            if (angka[i].se.se - angka[i].se.fi < ans.se - ans.fi) ans = angka[i].se;
        }
    }

    cout << ans.fi << " " << ans.se << endl;
}