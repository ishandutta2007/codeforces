#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;

map<char, int> cnt;
char s[maxn];
int n;

int main() {
    scanf("%d%s", &n, s);
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    REP(i, n) cnt[s[i]]++;
    FOR(i, 'a', 'z') if (cnt[i] >= 2) {
            puts("Yes");
            return 0;
        }
    puts("No");
    return 0;
}