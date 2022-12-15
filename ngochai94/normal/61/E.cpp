#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long n, lis[1000006], ans;
unordered_map<long long, long long> les, mor;
vector<long long> tmp;

void solve(int st, int en)
{
    //cout << st << ' ' << en << endl;
    if (en - st == 0)
    {
        les[lis[st]] = 0;
        mor[lis[st]] = 0;
        return;
    }
    int mid = (st + en) / 2;
    solve(st, mid);
    solve(mid + 1, en);
    int p1 = st;
    int p2 = mid + 1;
    long long rem1 = mid - st + 1;
    long long alr2 = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    FOR (i, st, mid) sum1 += mor[lis[i]];
    tmp.clear();
    //if (st == 0 && en == 4) BUG(sum2);
    //if (st == 0 && en == 4) BUG(sum1);
    //if (st == 0 && en == 4) BUG(ans);
    while (p1 <= mid && p2 <= en)
    {
        if (lis[p1] < lis[p2])
        {
            //cout << lis[p1];
            ans += sum2;
            sum1 -= mor[lis[p1]];
            les[lis[p1]] += alr2;
            tmp.pb(lis[p1++]);
            rem1--;
            //if (st == 0 && en == 4) BUG(ans);
        }
        else
        {
            //cout << lis[p2] << endl;
            ans += sum1;
            sum2 += les[lis[p2]];
            mor[lis[p2]] += rem1;
            tmp.pb(lis[p2++]);
            alr2++;
            //if (st == 0 && en == 4) BUG(ans);
        }
    }
    //if (st == 0 && en == 4) BUG(ans);
    FOR (i, p1, mid)
    {
        ans += sum2;
        les[lis[i]] += alr2;
        tmp.pb(lis[i]);
    }
    FOR (i, p2, en)
    {
        ans += sum1;
        tmp.pb(lis[i]);
    }
    FOR (i, st, en) lis[i] = tmp[i - st];
    //cout << st << ' ' << en << ' ' << ans << endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    solve(0, n - 1);
    cout << ans << endl;
    //REP (i, n) cout << lis[i] << ' ' << les[lis[i]] << endl;
}