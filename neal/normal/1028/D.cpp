#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

const int INF = 1e9 + 5, MOD = 1e9 + 7;

set<int> lower, upper, unknown;

int get_min(set<int> &s) {
    return s.empty() ? INF : *s.begin();
}

int get_max(set<int> &s) {
    return s.empty() ? -INF : *(--s.end());
}

void add(int price) {
    if (price <= get_max(lower)) {
        assert(lower.insert(price).second);
    } else if (price >= get_min(upper)) {
        assert(upper.insert(price).second);
    } else {
        assert(unknown.insert(price).second);
    }
}

int accept(int price) {
    if (price < get_max(lower) || price > get_min(upper))
        return 0;

    int status;

    if (price == get_max(lower)) {
        assert(lower.erase(price));
        status = 1;
    } else if (price == get_min(upper)) {
        assert(upper.erase(price));
        status = 1;
    } else {
        assert(unknown.erase(price));
        status = 2;
    }

    for (int p : unknown)
        if (p < price)
            lower.insert(p);
        else if (p > price)
            upper.insert(p);
        else
            assert(false);

    unknown.clear();
    return status;
}

int main() {
    int N;
    scanf("%d", &N);
    char operation[100];
    long long answer = 1;

    for (int i = 0; i < N; i++) {
        int price;
        scanf("%s %d", operation, &price);

        if (strcmp(operation, "ADD") == 0)
            add(price);
        else if (strcmp(operation, "ACCEPT") == 0)
            answer = answer * accept(price) % MOD;
        else
            assert(false);
    }

    answer = answer * (unknown.size() + 1) % MOD;
    cout << answer << '\n';
    return 0;
}