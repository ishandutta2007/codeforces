#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;



int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n;
    ios::sync_with_stdio(false);
    string str;
    cin >> n;
    cin >> str;
    string sol = str;
    for(i = 0; i + 1 < str.size(); i++) {
        if(str[i] > str[i + 1]) {
            sol.clear();
            for(int j = 0; j < str.size(); j++) {
                if(j != i) {
                    sol.push_back(str[j]);
                }
            }
            break;
        }
    }
    if(sol == str)
        sol.pop_back();
    cout << sol;
    //cin.close();
    //cout.close();
    return 0;
}