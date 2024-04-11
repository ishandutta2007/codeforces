#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

int main(){

    string s;
    cin >> s;
    for(int j = 0;j<s.size();j++){
        if(s[j] == '0'){
            s[j] = '-';
            for(int x = 0;x<s.size();x++){
                if(s[x] != '-'){
                    cout << s[x];
                }
            }
            exit(0);
        }
    }
    for(int j = 1;j<s.size();j++){
        cout << 1;
    }
    return 0;
}