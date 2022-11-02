#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int num_odd = 0;
    int num_even = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp % 2 == 1) ++num_odd;
        else ++num_even;
    }
    string winner = "";
    if (n == k) {
        if (num_odd % 2 == 1) winner = "Stannis";
        else winner = "Daenerys";
    } else {
        int num_turns = n-k;
        if (num_turns % 2 == 0) {
            //last_player is Daenerys
            winner = "Daenerys";
            if (num_turns / 2 >= num_even) {
                if (((num_turns - num_even) + num_odd) % 2 == 1) {
                    winner = "Stannis";
                }
            }
        } else {
            winner = "Stannis";
            if (num_turns / 2 >= num_even) {
                if (((num_turns - num_even) + num_odd) %2 == 0) {
                    winner = "Daenerys";
                }
            }
            if (num_turns / 2 >= num_odd) {
                winner = "Daenerys";
            }
        }
    }
    printf("%s\n", winner.c_str());
}