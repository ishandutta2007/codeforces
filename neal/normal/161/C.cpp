// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int K_MAX = 30;

vector<pair<int, int> > sub1, sub2;

// If there is a full substring, remove everything else
void reduce(vector<pair<int, int> > &v, int n)
{
    for (int i = 0; i < (int) v.size(); i++)
        if (v[i] == make_pair(0, n))
        {
            v.clear();
            v.push_back(make_pair(0, n));
            return;
        }
}

vector<pair<int, int> > split(pair<int, int> p, int n)
{
    vector<pair<int, int> > v;

    if (p.first < n)
        v.push_back(make_pair(p.first, min(p.second, n)));

    if (p.second > n + 1)
        v.push_back(make_pair(max(p.first, n + 1) - (n + 1), p.second - (n + 1)));

    return v;
}

int intersect(pair<int, int> a, pair<int, int> b)
{
    return min(a.second, b.second) - max(a.first, b.first);
}

int solve(int k)
{
    if (k == 0)
        return 0;

    int n = (1 << k) - 1, answer = 0;
    reduce(sub1, n);
    reduce(sub2, n);

    for (int i = 0; i < (int) sub1.size(); i++)
        for (int j = 0; j < (int) sub2.size(); j++)
            answer = max(answer, intersect(sub1[i], sub2[j]));

    vector<pair<int, int> > nsub1, nsub2;
    int nn = (1 << (k - 1)) - 1;

    for (int i = 0; i < (int) sub1.size(); i++)
    {
        vector<pair<int, int> > append = split(sub1[i], nn);
        nsub1.insert(nsub1.end(), append.begin(), append.end());
    }

    for (int i = 0; i < (int) sub2.size(); i++)
    {
        vector<pair<int, int> > append = split(sub2[i], nn);
        nsub2.insert(nsub2.end(), append.begin(), append.end());
    }

    sub1 = nsub1;
    sub2 = nsub2;
    return max(answer, solve(k - 1));
}

pair<int, int> get_pair()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    return make_pair(a, b);
}

int main()
{
    sub1.push_back(get_pair());
    sub2.push_back(get_pair());
    printf("%d\n", solve(K_MAX));
    return 0;
}