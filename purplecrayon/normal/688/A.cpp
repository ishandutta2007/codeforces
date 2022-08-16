#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d; cin >> n >> d;
    int ans=0, cur=0;
    while (d--){
        string s; cin >> s;
        if (count(s.begin(), s.end(), '0')) cur++;
        else cur = 0;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}