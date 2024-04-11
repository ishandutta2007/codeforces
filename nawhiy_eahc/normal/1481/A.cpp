#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int n = s.size();
        bool flag = true;
        int cnt = 0;
        if(x < 0){
            for(int i=0;i<n;i++){
                if(s[i] == 'L') cnt++;
            }
            if(cnt < -x) flag = false;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i] == 'R') cnt++;
            }
            if(cnt < x) flag = false;
        }
        cnt = 0;

        if(y < 0){
            for(int i=0;i<n;i++){
                if(s[i] == 'D') cnt++;
            }
            if(cnt < -y) flag = false;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i] == 'U') cnt++;
            }
            if(cnt < y) flag = false;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}