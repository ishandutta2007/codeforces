#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) FOR(i,0,a-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back

int n, m, lis[2222], cnt[2222], need, allow;
vector<int> v;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    FOR (i, 1, n)
    {
        cin >> lis[i];
        if (lis[i] > m || cnt[lis[i]] == n / m) v.pb(i);
        else cnt[lis[i]]++;
    }
    int ans = 0;
    //BUG(cnt[2]);
    FOR (i, 1, m) while (cnt[i] < n / m)
    {
        ans++;
        lis[v[v.size() - 1]] = i;
        v.pop_back();
        cnt[i]++;
    }
    cout << n / m << ' ' << ans << endl;
    FOR (i, 1, n) cout << lis[i] << ' ';
}