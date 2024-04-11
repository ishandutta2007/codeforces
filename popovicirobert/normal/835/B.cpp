#include <bits/stdc++.h>
#define ll long long


using namespace std;

int fr[10];
string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int k;
    cin >> k;
    cin >> str;
    int s = 0;
    for(auto it : str) {
        fr[it - '0']++;
        s += it - '0';
    }
    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        while(fr[i] > 0 && s < k) {
            fr[i]--;
            s += 9 - i;
            ans++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}