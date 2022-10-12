#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool vis[8] = {};
    if (s[0] == 'a') vis[0] = vis[1] = vis[2] = 1;
    if (s[0] == 'h') vis[4] = vis[5] = vis[6] = 1;
    if (s[1] == '1') vis[0] = vis[3] = vis[4] = 1;
    if (s[1] == '8') vis[2] = vis[7] = vis[6] = 1;
    
    int cnt = 0;
    for (int i=0; i<8; i++) cnt += vis[i] == 0;
    printf ("%d\n", cnt);
    return 0;
}