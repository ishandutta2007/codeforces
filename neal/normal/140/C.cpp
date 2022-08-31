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

int N;
map<int, int> radii;
priority_queue<pair<int, int> > groups;
vector<int> snowmen;

int main ()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int r;
        scanf("%d", &r);
        radii[r]++;
    }

    for (map<int, int>::iterator it = radii.begin(); it != radii.end(); it++)
        groups.push(make_pair(it->second, it->first));

    while (groups.size() >= 3)
    {
        pair<int, int> p1 = groups.top(); groups.pop();
        pair<int, int> p2 = groups.top(); groups.pop();
        pair<int, int> p3 = groups.top(); groups.pop();
        snowmen.push_back(p1.second); p1.first--;
        snowmen.push_back(p2.second); p2.first--;
        snowmen.push_back(p3.second); p3.first--;
        if (p1.first > 0) groups.push(p1);
        if (p2.first > 0) groups.push(p2);
        if (p3.first > 0) groups.push(p3);
    }

    printf("%d\n", (int) snowmen.size() / 3);

    for (int i = 0; i < (int) snowmen.size(); i += 3)
    {
        sort(snowmen.begin() + i, snowmen.begin() + i + 3);
        printf("%d %d %d\n", snowmen[i + 2], snowmen[i + 1], snowmen[i]);
    }

    return 0;
}