#include <bits/stdc++.h>


using namespace std;

string str;

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    long long ans = 0;
    for(i = 0; i < str.size(); i++) {
        str[i] -= '0';
        if(str[i] % 4 == 0)
           ans++;
        if(i > 0 && (str[i - 1] * 10 + str[i]) % 4 == 0)
           ans += i;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}