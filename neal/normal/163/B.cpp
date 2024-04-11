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

const int N_MAX = 1000005, ITER = 120;

struct lemming
{
    int weight, speed, original;

    bool operator < (const lemming &other) const
    {
        if (weight != other.weight)
            return weight < other.weight;

        return speed < other.speed;
    }
};

int N, K, H;
lemming lemmings[N_MAX];

vector<int> get_solution(double T)
{
    vector<int> answer;

    for (int i = 0, k = 1; i < N; i++)
        if (lemmings[i].speed * T >= (double) H * k)
        {
            answer.push_back(lemmings[i].original);
            k++;
        }

    return answer;
}

bool works(double T)
{
    return (int) get_solution(T).size() >= K;
}

int main ()
{
    scanf("%d %d %d", &N, &K, &H);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &lemmings[i].weight);
        lemmings[i].original = i;
    }

    for (int i = 0; i < N; i++)
        scanf("%d", &lemmings[i].speed);

    sort(lemmings, lemmings + N);
    double lo = 0, hi = 1;

    while (!works(hi))
        hi *= 2;

    for (int it = 0; it < ITER; it++)
    {
        double mid = (lo + hi) / 2;

        if (works(mid))
            hi = mid;
        else
            lo = mid;
    }

//    printf("%lf\n", hi);
    vector<int> answer = get_solution(hi);
    assert((int) answer.size() >= K);

    for (int i = 0; i < K; i++)
        printf("%d%c", answer[i] + 1, i < K - 1 ? ' ' : '\n');

    return 0;
}