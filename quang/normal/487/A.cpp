#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

struct data{
    int hp, atk, def;
} a, b, c;

int fee;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> a.hp >> a.atk >> a.def;
    cin >> b.hp >> b.atk >> b.def;
    cin >> c.hp >> c.atk >> c.def;
    fee  = 1000000010;
    for(int i = a.atk; i <= 200; i++)
    for(int j = a.def; j <= 100; j++) {
        int tang1 = max(0, i - b.def);
        int tang2 = max(0, b.atk - j);
        int sum  = (i - a.atk) * c.atk + (j - a.def) * c.def;
        if(!tang1) continue;
        int time = ((b.hp - 1) / tang1) + 1;
        if(!tang2) {
            fee = min(fee, sum);
            continue;
        }
        time = time * tang2;
        time++;
        sum += max(0, time - a.hp) * c.hp;
        fee = min(fee, sum);
    }
    cout << fee;
    return 0;
}