#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

string s;
int t, x = -1, y;

int main() {
    //fi, fo;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'F') {
            x++;
            if(i == x) continue;
            if(i - x > t) t = i - x;
            else t++;
        }
    }
    cout << t;

    return 0;
}