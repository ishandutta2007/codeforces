#include <bits/stdc++.h>
#define ll long long


using namespace std;

string str;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    while(n > 0) {
        str.clear();
        cin >> str;
        n -= str.size();
        int cnt = 0;
        for(auto it : str)
            if('A' <= it && it <= 'Z')
               cnt++;
        ans = max(ans, cnt);
        n--;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}