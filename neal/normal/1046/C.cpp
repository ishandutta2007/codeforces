#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, D;
int cscore[MAXN];
int nscore[MAXN];

bool works (int k)
{
    int mm = cscore[D] + nscore[0];
    int cloc = N - 1;
    for (int i = k; i < N; i++)
    {
        if (i == D) continue;
        if (cscore[i] + nscore[cloc] > mm)
            return false;
        cloc--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> D;
    D--;
    for (int i = 0; i < N; i++)
        cin >> cscore[i];
    for (int i = 0; i < N; i++)
        cin >> nscore[i];

    int lo = 0, hi = N - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo + 1 << "\n";
}