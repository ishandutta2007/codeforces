#include <bits/stdc++.h>


using namespace std;

string str;

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    for(i = 0; i < str.size(); i++) {
        str[i] -= 'a';
        int mx = -1, let;
        for(int j = 0; j < 26; j++)
           if(mx < abs(j - str[i]) && abs(j - str[i]) <= k) {
               mx = abs(j - str[i]);
               let = j;
           }
        k -= mx;
        str[i] = let + 'a';
    }
    if(k == 0)
        cout << str;
    else
        cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}