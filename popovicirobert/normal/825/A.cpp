#include <bits/stdc++.h>
#define long long ll


using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    int cnt = 0;
    for(i = 0; i < n; i++)
        if(str[i] == '1')
           cnt++;
        else {
             cout << cnt;
             cnt = 0;
        }
    cout << cnt;
    //cin.close();
    //cout.close();
    return 0;
}