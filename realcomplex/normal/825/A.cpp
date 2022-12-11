#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s >> s;
    string i;
    int t = 0;
    for(int x = 0;x<s.size();x++){
        if(s[x] == '1'){
            t++;
        }
        else{
            i += char(t+48);
            t = 0;
        }
    }
    i += char(t+48);
    cout << i;
    return 0;
}