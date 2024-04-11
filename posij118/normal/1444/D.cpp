#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int h;
        cin >> h;
        int sum1, sum2;
        sum1 = 0;
        sum2 = 0;

        int l[h];
        for(int i = 0; i<h; i++){
            cin >> l[i];
            sum1 += l[i];
        }

        int v;
        cin >> v;

        int p[v];
        for(int i = 0; i<v; i++){
            cin >> p[i];
            sum2 += p[i];
        }

        if(h != v){
            cout << "No" << endl;
            continue;
        }


        if(sum1 % 2 != 0 || sum2 % 2 != 0){
            cout << "No" << endl;
            continue;
        }

        int dp[sum1 / 2 + 1];
        fill(dp, dp + sum1 / 2 + 1, -1);

        int ma = 0;
        for(int i = 0; i<h; i++){
            for(int j = min(ma, sum1 / 2 - l[i]); j>=0; j--){
                if(j == 0 || dp[j] >= 0){
                    if(dp[j + l[i]] == -1) dp[j + l[i]] = i;
                }
            }

            ma = min(sum1 / 2, ma + l[i]);
        }

        if(dp[sum1 / 2] < 0){
            cout << "No" << endl;
            continue;
        }

        vector<int> posh, possh;
        int vish[h];
        fill(vish, vish + h, 0);
        int cur = sum1 / 2;
        while(cur > 0){
            posh.push_back(l[dp[cur]]);
            vish[dp[cur]] = 1;
            cur -= l[dp[cur]];
        }

        for(int i = 0; i<h; i++){
            if(vish[i] == 0) possh.push_back(l[i]);
        }

        int dp2[sum2 / 2 + 1];
        fill(dp2, dp2 + sum2 / 2 + 1, -1);

        ma = 0;
        for(int i = 0; i<v; i++){
            for(int j = min(ma, sum2 / 2 - p[i]); j>=0; j--){
                if(j == 0 || dp2[j] >= 0){
                    if(dp2[j + p[i]] == -1) dp2[j + p[i]] = i;
                }
            }

            ma = min(sum2 / 2, ma + p[i]);
        }

        if(dp2[sum2 / 2] < 0){
            cout << "No" << endl;
            continue;
        }

        vector<int> posv, possv;
        int visv[v];
        fill(visv, visv + v, 0);
        cur = sum2 / 2;
        while(cur > 0){
            posv.push_back(p[dp2[cur]]);
            visv[dp2[cur]] = 1;
            cur -= p[dp2[cur]];
        }

        for(int i = 0; i<v; i++){
            if(visv[i] == 0) possv.push_back(p[i]);
        }

        for(auto x: possh){
            //cout << x << " ";
        }
        //cout << endl;

         for(auto x: possv){
            //cout << x << " ";
        }

        //cout << endl;
        sort(posh.begin(), posh.end());
        sort(possh.begin(), possh.end());
        sort(posv.begin(), posv.end());
        sort(possv.begin(), possv.end());

        char start;
        if(posh.size() >= posv.size()){
            reverse(posv.begin(), posv.end());
            reverse(possv.begin(), possv.end());
            start = 'v';
        }

        else{
            reverse(posh.begin(), posh.end());
            reverse(possh.begin(), possh.end());
            start = 'h';
        }

        pair<int, int> cur_pos = {0, 0};

        cout << "Yes" << endl;
        for(int i = 0; i<h; i++){
            if(start == 'v'){
                if(i < posv.size()){
                    cout << cur_pos.first << " " << cur_pos.second + posv[i] << endl;
                    cur_pos.second += posv[i];
                }

                else{
                    cout << cur_pos.first << " " << cur_pos.second - possv[i - posv.size()] << endl;
                    cur_pos.second -= possv[i - posv.size()] ;
                }

                if(i < posh.size()){
                    cout << cur_pos.first + posh[i] << " " << cur_pos.second << endl;
                    cur_pos.first += posh[i];
                }

                else{
                    cout << cur_pos.first - possh[i - posh.size()] << " " << cur_pos.second << endl;
                    cur_pos.first -= possh[i - posh.size()];
                }
            }

            else{
                if(i < posh.size()){
                    cout << cur_pos.first + posh[i] << " " << cur_pos.second << endl;
                    cur_pos.first += posh[i];
                }

                else{
                    cout << cur_pos.first - possh[i - posh.size()] << " " << cur_pos.second << endl;
                    cur_pos.first -= possh[i - posh.size()];
                }

                if(i < posv.size()){
                    cout << cur_pos.first << " " << cur_pos.second + posv[i] << endl;
                    cur_pos.second += posv[i];
                }

                else{
                    cout << cur_pos.first << " " << cur_pos.second - possv[i - posv.size()] << endl;
                    cur_pos.second -= possv[i - posv.size()];
                }
            }
        }

    }

}