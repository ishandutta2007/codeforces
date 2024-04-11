#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define long long long

using namespace std;

//ifstream cin("power.in");
//ofstream cout("power.out");

const int MAXN = 1000001;
int box_size;

struct query
{
    int first, second, num;
    long res;
};

long A[MAXN];
int counter[MAXN];
query queries[MAXN];
long out[MAXN];

bool comp(query A, query B)
{
    if (A.first / box_size == B.first / box_size)
        return A.second > B.second;
    return A.first < B.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    box_size = int(sqrt(n)) + 1;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < t; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--, queries[i].second--;
        queries[i].num = i;
        queries[i].res = 0;
    }
    sort(queries, queries + t, comp);
    int l = 0, r = 0;
    long res = A[0];
    counter[A[0]]++;

    for (int i = 0; i < t; i++)
    {

        while (l > queries[i].first)
        {
            l--;
            counter[A[l]]++;
            res += (2 * counter[A[l]] - 1) * A[l];
        }

        while (r < queries[i].second)
        {
            r++;
            counter[A[r]]++;
            res += (2 * counter[A[r]] - 1) * A[r];
        }

        while (r > queries[i].second)
        {
            res -= (2 * counter[A[r]] - 1) * A[r];
            counter[A[r]]--;
            r--;
        }

        while (l < queries[i].first)
        {
            res -= (2 * counter[A[l]] - 1) * A[l];
            counter[A[l]]--;
            l++;
        }

        queries[i].res = res;
    }

    for (int i = 0; i < t; i++)
        out[queries[i].num] = queries[i].res;

    for (int i = 0; i < t; i++)
        cout << out[i] << '\n';
    return 0;
}