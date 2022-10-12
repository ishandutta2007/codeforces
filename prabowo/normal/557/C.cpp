#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

typedef pair<int, int> pii;

int n;
pii leg[100002];
int num[202];

int main() {
    scanf("%d", &n);

    int all = 0;

    for (int i=0; i<n; i++) scanf("%d", &leg[i].fi);
    for (int i=0; i<n; i++) scanf("%d", &leg[i].se), all += leg[i].se;

    sort(leg, leg+n);
    leg[n].fi = leg[n-1].fi + 1;

    int ans = all;

    for (int i=0; i<n; ) {
        int cnt = 0;
        int idx = i;
        int now = leg[i].fi;
        while (now == leg[idx].fi) all -= leg[idx].se, idx++, cnt++;

        int buang = idx - 2 * cnt + 1;
        int tenaga = 1;
        int sum = 0;
        while (buang > 0) {
            sum += num[tenaga] * tenaga;
            buang -= num[tenaga];
            tenaga++;
        }
        sum += buang * (tenaga - 1);

        for (int j=i; j<idx; j++) num[leg[j].se]++;

        //cout << sum << " " << all << endl;
        ans = min(ans, sum + all);

        i = idx;
    }

    printf("%d\n", ans);
    return 0;
}