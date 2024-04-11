#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long LA, RA, TA;
long long LB, RB, TB;

long long evaluate(long long NA, long long NB, long long offset) {
    if (offset < 0)
        return min(NA + offset, NB);
    else
        return min(NA, NB - offset);
}

long long solve() {
    long long NA = RA - LA;
    long long NB = RB - LB;
    long long G = __gcd(TA, TB);
    long long offset = (LA - LB) % G;
    long long answer = evaluate(NA, NB, offset);
    answer = max(answer, evaluate(NA, NB, offset + G));
    answer = max(answer, evaluate(NA, NB, offset - G));
    return answer;
}

int main() {
    scanf("%lld %lld %lld %lld %lld %lld", &LA, &RA, &TA, &LB, &RB, &TB);
    RA++; RB++;
    assert(LA > 0 || RA < TA);
    assert(LB > 0 || RB < TB);

    long long best = 0;
    best = max(best, solve());
    swap(LA, LB);
    swap(RA, RB);
    swap(TA, TB);
    best = max(best, solve());
    printf("%lld\n", best);
}