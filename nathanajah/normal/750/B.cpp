#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    int current_pos;
    scanf("%d", &n);
    current_pos = 10000;
    bool valid = true;
    for (int i = 0; i < n; i++) {
        int dist;
        char c[10005];
        string s;
        scanf("%d %s", &dist, c);
        s = c;
        int movement = 0;
        if (s == "South") {
            movement = -dist;
        } else if (s == "North") {
            movement = dist;
        }
        if (current_pos == 10000 && s != "South") {
            valid = false;
        }
        if (current_pos == -10000 && s != "North") {
            valid = false;
        }
        if (current_pos + movement > 10000) {
            valid = false;
        }
        if (current_pos + movement < -10000) {
            valid = false;
        }
        current_pos += movement;
    }
    if (current_pos != 10000) {
        valid = false;
    }
    printf(valid ? "YES\n" : "NO\n");
}