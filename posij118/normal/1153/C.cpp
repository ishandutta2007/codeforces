#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size() % 2){
        cout << ":(";
        return 0;
    }

    int cur, l, r;
    l = s.size()/2;
    r = s.size()/2;

    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(') l--;
        else if(s[i] == ')') r--;
    }

    for(int i = s.size() - 1; i>=0; i--){
        if(s[i] == '?' && r > 0){
            s[i] = ')';
            r--;
        }

        else if(s[i] == '?'){
            s[i] = '(';
            l--;
        }
    }

    if(l != 0 || r != 0){
        cout << ":(";
        return 0;
    }

    cur = 0;
    for(int i = 0; i<s.size() - 1; i++){
        if(s[i] == '(') cur++;
        else cur--;
        if(cur <= 0){
            cout << ":(";
            return 0;
        }
    }

    cout << s;
}