#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int LOGN = 17;
pair<int, int> queries[MAXN + 1];
tuple<int, int, int> orderedQueries[MAXN + 1];
int pos[MAXN + 1];
long long active[MAXN + 1];
long long activeLight[MAXN + 1];
long long power[MAXN + 1];
int numFire = 0;
int numLight = 0;
map<int, int> mLight;
map<int, int> mFire;
priority_queue<int, vector<int>, greater<int>> minLight;
priority_queue<int> maxFire;

long long query(int ind, long long bit[MAXN + 1])
{
    long long ans = 0;
    while (ind)
    {
        ans += bit[ind];
        ind -= ind & -ind;
    }
    return ans;
}

void inc(int ind, int amt, long long bit[MAXN + 1])
{
    while (ind <= MAXN)
    {
        bit[ind] += amt;
        ind += ind & -ind;
    }
}

int getInd(long long amt, long long bit[MAXN + 1])
{
    int ans = 0;
    for (int i = LOGN; i >= 0; i--)
    {
        int jump = 1 << i;
        if (ans + jump > MAXN)
            continue;
        if (bit[ans + jump] < amt)
        {
            ans += jump;
            amt -= bit[ans];
        }
    }
    return ans + 1;
}

long long solve()
{
    if (numLight == 0)
    {
        return 0;
    }
    int ind = getInd(numLight, active);
    bool allLight = query(ind, activeLight) == numLight;
    long long offset = 0;
    if (allLight)
    {
        while (!mLight.count(minLight.top()))
            minLight.pop();
        offset = -minLight.top();
        if (numFire)
        {
            while (!mFire.count(maxFire.top()))
                maxFire.pop();
            offset += maxFire.top();
        }
    }
    return query(ind, power) + offset;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tp, d;
        cin >> tp >> d;
        queries[i] = make_pair(tp, d);
        orderedQueries[i] = make_tuple(d, tp, i);
    }
    sort(orderedQueries + 1, orderedQueries + n + 1);
    reverse(orderedQueries + 1, orderedQueries + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (get<0>(orderedQueries[i]) < 0)
            break;
        pos[get<2>(orderedQueries[i])] = i;
    }
    long long totalPower = 0;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> pr = queries[i];
        int tp = pr.first;
        int d = pr.second;
        totalPower += d;
        if (d > 0)
        {
            int p = pos[i];
            inc(p, 1, active);
            inc(p, d, power);
            if (tp)
            {
                mLight[d] = p;
                numLight++;
                inc(p, 1, activeLight);
                minLight.push(d);
            }
            else
            {
                mFire[d] = p;
                numFire++;
                maxFire.push(d);
            }
        }
        else
        {
            int p = 0;
            if (tp)
                p = mLight[-d];
            else
                p = mFire[-d];
            inc(p, -1, active);
            inc(p, d, power);
            if (tp)
            {
                mLight.erase(-d);
                numLight--;
                inc(p, -1, activeLight);
            }
            else
            {
                mFire.erase(-d);
                numFire--;
            }
        }
        cout << totalPower + solve() << "\n";
    }
    return 0;
}