#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int N_MAX = 105, SUM_MAX = 10005;

int N;
float ways[N_MAX][SUM_MAX];

int main() {
    scanf("%d", &N);
    map<int, int> freq;

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        freq[a]++;
    }

    for (int s = 0; s < SUM_MAX; s++)
        ways[0][s] = 0;

    ways[0][0] = 1;
    int so_far = 0;

    for (auto &p : freq) {
        int A = p.first, occur = p.second;

        for (int count = so_far; count >= 0; count--)
            for (int add = occur; add > 0; add--)
                for (int s = 0; s + add * A < SUM_MAX; s++)
                    ways[count + add][s + add * A] += ways[count][s];

        so_far += occur;
    }

    int answer = freq.size() <= 2 ? N : 0;

    for (auto &p : freq) {
        int A = p.first, occur = p.second;

        for (int count = 1; count <= occur; count++)
            if (ways[count][count * A] == 1)
                answer = max(answer, count);
    }

    printf("%d\n", answer);
}