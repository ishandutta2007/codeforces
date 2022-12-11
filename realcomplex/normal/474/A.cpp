#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    string key[3];
    key[0] = "qwertyuiop";
    key[1] = "asdfghjkl;";
    key[2] = "zxcvbnm,./";
    char v;
    cin >> v;
    string s;
    cin >> s;
    int c;
    if(v == 'R'){
        c = 1;
    }
    else{
        c = -1;
    }
    for(int j = 0;j<s.size();j++){
        if(key[0].find(s[j]) != -1){
            cout << key[0][key[0].find(s[j])-c];
        }
        else if(key[1].find(s[j])!=-1){
            cout << key[1][key[1].find(s[j])-c];
        }
        else{
            cout << key[2][key[2].find(s[j])-c];
        }
    }
    return 0;
}