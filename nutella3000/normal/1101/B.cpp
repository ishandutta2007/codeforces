#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
   //freopen("transform.in", "r", stdin);
    //freopen("transform.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;int n;
    cin >> s;
    n = s.size();
    int ind1 = -1;
    int ind4 = -1;
    int ind2 = -1;
    int ind3 = -1;
    for(int i = 0;i < n;i++) {
        if (s[i] == '[') {
            ind1 = i;
            break;
        }
    }
    for(int i = 0;i < n;i++) {
        if (s[i] == ']' && i > ind1) {
            ind4 = i;
        }
    }
    for(int i = 0;i < n;i++) {
        if (s[i] == ':' && i > ind1 && i < ind4) {
            ind2 = i;
            break;
        }
    }
    for(int i = 0;i < n;i++) {
        if (s[i] == ':' && i > ind2 && i < ind4) {
            ind3 = i;
        }
    }
    if (ind1 == -1 || ind2 == -1 || ind3 == -1 || ind4 == -1) {
        cout << -1;
    }else {
        int cnt = 4;
        for (int i = ind2; i < ind3; i++) {
            if (s[i] == '|') cnt++;
        }
        cout << cnt;
    }
}