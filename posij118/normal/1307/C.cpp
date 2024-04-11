#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;

    for(int i = 0; i<26; i++){
        long long cnt = 0;
        for(int j = 0; j<n; j++){
            if(s[j] == 'a' + i) cnt++;
        }

        ans = max(ans, cnt);
    }

    for(int i = 0; i<26; i++){
        for(int k = 0; k<26; k++){
            long long cnt = 0;
            int occ = 0;
            for(int j = 0; j<n; j++){
if(s[j] == 'a' + k) cnt += occ;
                if(s[j] == 'a' + i) occ++;

            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;

}