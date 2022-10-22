#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        int even = 0, zero = 0, sum = 0;
        for(int i=0;i<(int)s.size();i++){
            sum += s[i] - '0';
            if(s[i] - '0' == 0) zero++;
            if((s[i] - '0')%2 == 0) even++;
        }

        if(even >= 2 && zero >= 1 && sum%3 == 0) cout << "red\n";
        else cout << "cyan\n";
    }
}