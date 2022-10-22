#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int s; cin >> s;
        int now = 1;
        while(now*now < s) now++;
        cout << now << "\n";
    }
}