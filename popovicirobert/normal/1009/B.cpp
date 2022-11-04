#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

int fr[10];
string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    int sz = str.size();
    for(i = 0; i < sz; i++) {
        str[i] -= '0';
    }
    i = 0;
    while(i < sz && str[i] != 2) {
        fr[str[i]]++;
        i++;
    }
    while(fr[0] > 0) {
        cout << 0;
        fr[0]--;
    }
    for(auto it : str) {
        if(it == 1)
            cout << 1;
    }
    while(i < sz) {
        if(str[i] != 1)
            cout << (int) str[i];
        i++;
    }
    //cin.close();
    //cout.close();
    return 0;
}