#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <numeric>
#include <cctype>
#include <cmath>
#include <bitset>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cassert>
using namespace std;

const int MAX = 1000010;

struct range_increment
{
    int N;
    long long tree[MAX];

    void init(int n)
    {
        N = n + 2;
        memset(tree, 0, sizeof(tree));
    }

    void modify(int x, long long change)
    {
        for (int i = x; i <= N; i += i & -i)
            tree[i] += change;
    }

    // a to b inclusive
    void increment(int a, int b, long long x)
    {
        modify(a, x);
        modify(b + 1, -x);
    }

    long long get(int x)
    {
        long long sum = 0;

        for (int i = x; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }
};

int N, M, left_count[MAX], right_count[MAX];
long long heights[MAX];
pair<long long, int> sorted[MAX];
range_increment plateau, multiplier;

int main()
{
    scanf("%d", &N);
    plateau.init(N);
    multiplier.init(N);

    for (int i = 0; i < N; i++)
    {
        int h;
        scanf("%d", &h);
        heights[i] = h;
        sorted[i] = make_pair(heights[i], i);
    }

    sort(sorted, sorted + N);
    set<int> already;
    already.insert(-1);
    already.insert(N);

    for (int i = 0; i < N; i++)
    {
        int ind = sorted[i].second;
        set<int>::iterator after = already.upper_bound(ind);
        set<int>::iterator before = after;
        before--;
        left_count[ind] = ind - *before;
        right_count[ind] = *after - ind;
        already.insert(ind);
    }

    for (int i = 0; i < N; i++)
    {
        int low = min(left_count[i], right_count[i]);
        int high = max(left_count[i], right_count[i]);
        assert(low >= 1);
        assert(high <= N);
        multiplier.increment(1, low, heights[i]);

        if (high - low >= 2)
            plateau.increment(low + 1, high - 1, (long long) low * heights[i]);

        multiplier.increment(high, low + high - 1, -heights[i]);
        plateau.increment(high, low + high - 1, (long long) (low + high) * heights[i]);

        if (low == high)
            plateau.increment(low, low, (long long) -low * heights[i]);
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int k;
        scanf("%d", &k);
        long long sum = plateau.get(k) + (long long) k * multiplier.get(k);
        printf("%.16lf\n", (double) sum / (N - k + 1));
    }

    return 0;
}