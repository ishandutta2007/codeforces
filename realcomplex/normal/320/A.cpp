/*
   .
#???????
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int cnt = 1e9;
    for(int i = 0;i<int(s.size());i++){
        if(s[i] != '1' && s[i] != '4'){
            cout << "NO";
            exit(0);
        }
        if(s[i] == '4'){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt > 2){
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    return 0;
}