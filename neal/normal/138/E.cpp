// Codeforces 99E: "Hellish Constraints"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N_MAX = 100005, K_MAX = 505;

struct constraint
{
    char letter;
    int low, high;
};

int N, K, L, R;
char str[N_MAX];
constraint constraints[K_MAX];
int start[K_MAX], end[K_MAX], start_count[K_MAX], end_count[K_MAX], done_count[K_MAX];
int valid_constraints[N_MAX], LR_good;
long long total;

inline bool betweenLR(int pos)
{
    return L <= valid_constraints[pos] && valid_constraints[pos] <= R;
}

inline void modify(int pos, int change)
{
    int before = betweenLR(pos);
    valid_constraints[pos] += change;
    int after = betweenLR(pos);
    LR_good += after - before;
}

int main()
{
    scanf("%s %d %d %d", str, &K, &L, &R);
    N = strlen(str);

    for (int k = 0; k < K; k++)
        scanf(" %c %d %d", &constraints[k].letter, &constraints[k].low, &constraints[k].high);

    total = 0;
    LR_good = L == 0 ? N + 1 : 0;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < K; k++)
        {
            char c = constraints[k].letter;
            int low = constraints[k].low, high = constraints[k].high;

            while (start[k] < i + 1)
                start_count[k] += str[start[k]++] == c ? 1 : 0;

            while (end[k] < i + 1)
                end_count[k] += str[end[k]++] == c ? 1 : 0;

            while (start[k] <= N && start_count[k] - done_count[k] < low)
            {
                start_count[k] += str[start[k]] == c ? 1 : 0;
                modify(start[k]++, -1);
            }

            while (end[k] <= N && end_count[k] - done_count[k] <= high)
            {
                end_count[k] += str[end[k]] == c ? 1 : 0;
                modify(end[k]++, 1);
            }

            done_count[k] += str[i] == c ? 1 : 0;
        }

// endpoint must be at least i + 1
        LR_good -= betweenLR(i);
        total += LR_good;
    }

    cout << total << '\n';
    return 0;
}