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

char s[maxn];
int cnt[3], tmp[maxn];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	REP(i, n) {
		if (s[i] == '1') cnt[1]++;
		else if (s[i] == '2') {
			tmp[cnt[2]] = 2;
			cnt[2]++;
		} else {
			if (!cnt[2]) cnt[0]++;
			else {
				tmp[cnt[2]] = 0;
				cnt[2]++;
			}
		}
	}
	REP(i, cnt[0]) putchar('0');
	REP(i, cnt[1]) putchar('1');
	REP(i, cnt[2]) printf("%d", tmp[i]);
	return 0;
}