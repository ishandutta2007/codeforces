#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    if(S.size() == 1) {
        if('1' <= S[0] && S[0] <= '9') {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
    else {
        int ans = 0;
        for(int i = pow(10,S.size()-2); i < pow(10,S.size()-1); i++) {
            if(i%10 == 0 || i%10 == 2 || i%10 == 5 || i%10 == 7) {
                string s = to_string(i)+'0';
                bool flag = false;
                char a = 'a';
                for(int j = 0; j < s.size(); j++) {
                    if('0' <= S[j] && S[j] <= '9') {
                        if(S[j] != s[j]) {
                            flag = true;
                            break;
                        }
                    }
                    else if(S[j] == 'X') {
                        if(a == 'a') {
                            a = s[j];
                        }
                        else if(a != s[j]) {
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag && (i%10 == 0 || i%10 == 5)) {
                    ans++;
                }
                s.back() = '5';
                flag = false;
                a = 'a';
                for(int j = 0; j < s.size(); j++) {
                    if('0' <= S[j] && S[j] <= '9') {
                        if(S[j] != s[j]) {
                            flag = true;
                            break;
                        }
                    }
                    else if(S[j] == 'X') {
                        if(a == 'a') {
                            a = s[j];
                        }
                        else if(a != s[j]) {
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag && (i%10 == 2 || i%10 == 7)) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}