#include <bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;

int main(){
    srand(time(NULL));
    int n, m, pos, o, ans, skap;
    ans = 0;
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();

    long long zer, one;
    long long zh, oh;
    int zpos, opos;
    zer = 0;
    one = 0;

    for(int i = 0; i<n; i++){
        if(s[i] == '0') zer++;
        else one++;
    }

    long long h[m + 1];
    long long p = 152484161 + rand() % (1 << 16);
    long long pr[m + 1];
    pr[0] = 1;
    for(int i = 1; i<m + 1; i++){
        pr[i] = pr[i - 1] * p;
        pr[i] %= M;
    }

    h[0] = 0;
    for(int i = 1; i<m + 1; i++){
        h[i] = h[i - 1] + pr[i - 1] * (t[i - 1] - 'a' + 1);
        h[i] %= M;
    }

    for(int i = 1; i<m; i++){

        if((i * zer) < m && (((m - (i*zer)) % one) == 0)){
            o = (m - i*zer) / one;
            pos = 0;
            zpos = -1;
            opos = -1;
            skap = 0;
            // cout << i << endl;
            for(int j = 0; j<n; j++){

                if(s[j] == '1' && opos == -1){
                    opos = pos;
                    oh = (((h[pos + o] - h[pos]) % M) + M) % M;
                }

                if(s[j] == '0' && zpos == -1){
                    zpos = pos;
                    zh = (((h[pos + i] - h[pos]) % M) + M) % M;
                }

                if(s[j] == '1'){
                    if((oh * pr[pos - opos]) % M != (((h[pos + o] - h[pos]) % M) + M) % M){
                        skap = 1;
                    }
                }

                if(s[j] == '0'){
                    if((zh * pr[pos - zpos]) % M != (((h[pos + i] - h[pos]) % M) + M) % M){
                        skap = 1;
                    }
                }

                if(skap == 1) break;
                if(i == o && opos > -1 && zpos > -1 && zpos < opos){
                    if((zh * pr[opos - zpos]) % M == oh) break;
                }

                if(i == o && opos > -1 && zpos > -1 && zpos > opos){
                    if((oh * pr[zpos - opos]) % M == zh) break;
                }

                if(s[j] == '0') pos += i;
                else pos += o;
                if(j == n - 1) ans++;
            }
        }
    }

    cout << ans;
}