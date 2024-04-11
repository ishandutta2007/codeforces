#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s1;
        cin >> s1;
        int ans = 10;

        string s2 = s1;
        int n = s1.size();

        for(int i = 0; i<n; i++){
            if(s1[i] == '?') s1[i] = '0' + (i % 2);
            if(s2[i] == '?') s2[i] = '0' + 1 - (i % 2);
        }

        int cnt1 = 0;
        int cnt2 = 0;
        int rem1 = 5;
        int rem2 = 5;

        for(int i = 0; i<n; i++){
            if(i % 2){
                if(s1[i] == '1') cnt1++;
                rem1--;
            }

            else{
                if(s1[i] == '1') cnt2++;
                rem2--;
            }

            if(cnt1 > cnt2){
                if(cnt2 + rem2 < cnt1){
                    ans = min(ans, i + 1);
                    break;
                }
            }

            else{
                if(cnt1 + rem1 < cnt2){
                    ans = min(ans, i + 1);
                    break;
                }
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        rem1 = 5;
        rem2 = 5;

        for(int i = 0; i<n; i++){
            if(i % 2){
                if(s2[i] == '1') cnt1++;
                rem1--;
            }

            else{
                if(s2[i] == '1') cnt2++;
                rem2--;
            }

            if(cnt1 > cnt2){
                if(cnt2 + rem2 < cnt1){
                    ans = min(ans, i + 1);
                    break;
                }
            }

            else{
                if(cnt1 + rem1 < cnt2){
                    ans = min(ans, i + 1);
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}