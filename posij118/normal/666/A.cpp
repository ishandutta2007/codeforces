#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t, u;
    cin >> s;
    int n = s.size();

    int dp[n][2];
    vector<string> ans;
    set<string> opt;
    dp[n - 1][0] = 0;
    dp[n - 1][1] = 0;
    dp[n - 2][0] = 1;
    if(n >=7){
        t.push_back(s[n - 2]);
        t.push_back(s[n - 1]);
        if(!opt.count(t)){
            opt.insert(t);
            ans.push_back(t);
        }
    }
    dp[n - 2][1] = 0;
    dp[n - 3][0] = 0;
    dp[n - 3][1] = 1;
    if(n >= 8){
        t.clear();
        t.push_back(s[n - 3]);
        t.push_back(s[n - 2]);
        t.push_back(s[n - 1]);
        if(!opt.count(t)){
            opt.insert(t);
            ans.push_back(t);
        }
    }

    for(int i = n - 4; i>=5; i--){
        if(dp[i + 2][1] == 1){
                dp[i][0] = 1;
                t.clear();
                t.push_back(s[i]);
                t.push_back(s[i + 1]);
                if(!opt.count(t)){
                    opt.insert(t);
                    ans.push_back(t);
                }
        }

        else if(dp[i + 2][0] == 1){
            t.clear();
            t.push_back(s[i]);
            t.push_back(s[i + 1]);
            u.clear();
            u.push_back(s[i + 2]);
            u.push_back(s[i + 3]);
            if(t != u){

                dp[i][0] = 1;
                if(!opt.count(t)){
                    opt.insert(t);
                    ans.push_back(t);
                }
            }
        }

        if(dp[i + 3][0] == 1){
                dp[i][1] = 1;
                t.clear();
                t.push_back(s[i]);
                t.push_back(s[i + 1]);
                t.push_back(s[i + 2]);
                if(!opt.count(t)){
                    opt.insert(t);
                    ans.push_back(t);
                }
        }

        else if(dp[i + 3][1] == 1){
            t.clear();
            t.push_back(s[i]);
            t.push_back(s[i + 1]);
            t.push_back(s[i + 2]);
            u.clear();
            u.push_back(s[i + 3]);
            u.push_back(s[i + 4]);
            u.push_back(s[i + 5]);
            if(t != u){
                dp[i][1] = 1;
                if(!opt.count(t)){
                    opt.insert(t);
                    ans.push_back(t);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}