#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;

    int s[n], cnt[n];
    fill(cnt, cnt + n, 0);

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        x--;

        s[i] = x;
        cnt[x]++;
    }

    vector<int> hunger[n];

    for(int i = 0; i<m; i++){
        int f, h;
        cin >> f >> h;
        f--;

        hunger[f].push_back(h);
    }

    for(int i = 0; i<n; i++){
        sort(hunger[i].begin(), hunger[i].end());
    }

    int ma = 0;
    long long ans = 1;

    int cur[n];
    fill(cur, cur + n, 0);

    for(int i = -1; i<n; i++){
        if(i != -1) cur[s[i]]++;
        long long opt = 1;
        long long num = 0;

        for(int f = 0; f<n; f++){
            int other = cnt[f] - cur[f];
            int ths = cur[f];

            int ths_ok = 0;
            int other_ok = 0;

            if(i == -1 || f != s[i] ){
                if(other < ths) swap(ths, other);

                for(int j = 0; j<hunger[f].size(); j++){
                    if(hunger[f][j] <= ths) ths_ok++;
                    if(hunger[f][j] <= other) other_ok++;
                }

                if(ths_ok && other_ok > 1){
                    opt *= ths_ok * (other_ok - 1);
                    num += 2;
                }

                else if(other_ok && !ths_ok){
                    opt *= other_ok;
                    num++;
                }

                else if(ths_ok == other_ok && ths_ok == 1){
                    opt *= 2;
                    num++;
                }

                opt %= M;
            }

            else{
                for(int j = 0; j<hunger[f].size(); j++){
                    if(hunger[f][j] == ths) ths_ok++;
                    if(hunger[f][j] <= other && hunger[f][j] != ths) other_ok++;
                }

                if(ths_ok == 0) opt *= 0;

                else{
                    if(other_ok == 0){
                        num++;
                    }

                    else{
                        opt *= other_ok;
                        num += 2;
                    }
                }

                opt %= M;
            }
        }

        if(num > ma){
            ma = num;
            ans = opt;
        }

        else if(num == ma){
            ans += opt;
            ans %= M;
        }
    }

    if(ma == 0) cout << ma << " " << 1 << endl;
    else cout << ma << " " << ans << endl;

}