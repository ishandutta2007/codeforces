#include <bits/stdc++.h>


using namespace std;

int dl[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int l;
    char c;
    ios::sync_with_stdio(false);
    cin >> c;
    cin >> l;
    c -= 'a' - 1;
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        int x = l + dl[i];
        int y = c + dc[i];
        if(x >= 1 && y >= 1 && x <= 8 && y <= 8)
            ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}