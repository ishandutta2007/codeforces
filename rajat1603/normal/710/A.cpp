#include "bits/stdc++.h"
using namespace std;
int main(){
    string str;
    cin >> str;
    int ans = -1;
    int x = str[0] - 'a' + 1;
    int y = str[1] - '0';
    for(int dx = -1 ; dx <= 1 ; ++dx){
        for(int dy = -1 ; dy <= 1 ; ++dy){
            int nx = x + dx;
            int ny = y + dy;
            ans += (min(nx , ny) >= 1) && (max(nx , ny) <= 8);
        }
    }
    cout << ans;
}