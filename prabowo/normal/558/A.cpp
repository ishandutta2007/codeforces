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
pii apple[102];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d %d", &apple[i].fi, &apple[i].se);
    apple[n++] = mp(0, 0);
    sort(apple, apple+n);

    int idx = lower_bound(apple, apple+n, mp(0, 0)) - apple;

    int ambil = min(n-idx-1, idx);
    int ans = 0;
    for (int i=idx+1; i<=idx+ambil; i++) ans += apple[i].se;
    for (int i=idx-1; i>=idx-ambil; i--) ans += apple[i].se;

    if (idx + ambil < n-1) ans += apple[idx+ambil+1].se;
    else if (idx - ambil > 0) ans += apple[idx-ambil-1].se;

    cout << ans << endl;
}