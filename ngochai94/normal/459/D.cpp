#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

int n, lis[1000006], BIT[1000006];

int get(int ind) {
    int res = 0;
    while (ind > 0) {
        res += BIT[ind];
        ind -= ind & (-ind);
    }
    return res;
}

void update(int ind, int val) {
    while (ind <= n) {
        BIT[ind] += val;
        ind += ind & (-ind);
    }
}

unordered_map<int, int> cnt, cnt2;

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    // cin >> n;
    scanf("%d", &n);
    FOR (i, 1, n) {
        // cin >> lis[i];
        scanf("%d", &lis[i]);
        cnt[lis[i]]++;
        update(cnt[lis[i]], 1);
    }
    long long ans = 0;
    FOR (i, 1, n - 1) {
        cnt2[lis[i]]++;
        int tmp = cnt[lis[i]];
        cnt[lis[i]]--;
        update(tmp, -1);
        ans += get(cnt2[lis[i]] - 1);
    }
    // cout << ans;
    printf("%lld", ans);
}