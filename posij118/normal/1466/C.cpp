#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(i >= 1){
                if(s[i] == s[i - 1]){
                    s[i] = 'z' + 1 + (i % 4);
                    ans++;
                }
            }

            if(i >= 2){
                if(s[i] == s[i - 2]){
                    s[i] = 'z' + 1 + (i % 4);
                    ans++;
                }
            }
        }

        cout << ans << endl;

    }

}