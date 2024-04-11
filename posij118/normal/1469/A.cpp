#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        if(s.size() % 2){
            cout << "NO" << endl;
            continue;
        }

        int cnt = 0;
        int diff = 0;
        bool flag = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == ')') diff--;
            else if(s[i] == '(') diff++;

            else if(cnt < s.size() / 2 - 1){
                cnt++;
                diff++;
            }

            else{
                diff--;
            }

            if(diff < 0){
                cout << "NO" << endl;
                flag = 1;
                break;
            }

        }

        if(!flag) cout << "YES" << endl;
    }

}