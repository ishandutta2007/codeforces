#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int flag1 = 0;
        int flag2 = 0;
        int good = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '<') flag1 = 1;
            if(s[i] == '>') flag2 = 1;
            if(s[i] == '-' || s[(i + 1) % n] == '-') good++;
        }

        if(flag1 && flag2) cout << good << endl;
        else cout << n << endl;
    }

}