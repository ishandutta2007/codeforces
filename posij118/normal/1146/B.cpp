
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;

    for(int i = 0; i<s.size(); i++){
        if(s[i] != 'a') cnt++;
    }

    if(cnt % 2){
        cout << ":(";
        return 0;
    }

    int chars[cnt/2];
    int used = 0;
    int last = 0;

    for(int i = 0; i<s.size(); i++){
        if(s[i] != 'a'){
            if(used < cnt/2){
                chars[used] = s[i];
                used++;
            }

            else{
                if(s[i] != chars[used - cnt/2]){
                    cout << ":(";
                    return 0;
                }
                used++;
            }
        }

        if(used <= cnt/2) last = i;
        if(used > cnt/2 && s[i] == 'a' && used){
            cout << ":(";
            return 0;
        }
    }

    for(int i = 0; i<=last; i++){
        cout << s[i];
    }
}