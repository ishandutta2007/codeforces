#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();

    int p[n + 1];
    int ne[n];
    int pr[n];
    int debug[10];
    fill(debug, debug + 10, 0);
    long long ans = 0;
    for(int i = 1; i<=250; i++){
        fill(p, p + n + 1, 0);
        for(int j = 0; j<n; j++){
            if(s[j] == '1') p[j + 1] = p[j] + (i - 1);
            else p[j + 1] = p[j] - 1;
        }

        sort(p, p + n + 1);
        /*if(i == 2){
            for(int j = 0; j<n + 1; j++){
                cout << p[j] << " ";
            }
        }
        */

        long long cur = 0;
        for(int j = 0; j<n + 1; j++){
            cur++;
            if(j == n) ans += (cur * (cur - 1)) / 2;
            else if(p[j] != p[j + 1]){
                ans += (cur * (cur - 1)) / 2;
                cur = 0;
            }
        }
    }

    int cur = n;
    for(int i = n - 1; i>=0; i--){
        if(s[i] == '1'){
            ne[i] = cur;
            cur = i;
        }
    }

    p[0] = 0;
    cur = -1;
    for(int i = 0; i<n; i++){
        if(s[i] == '0') p[i + 1] = p[i] + 1;
        else p[i + 1] = p[i];

        if(s[i] == '1'){
            pr[i] = cur;
            cur = i;
        }
    }

    for(int i = 0; i<n; i++){
        //cout << p[i] << " ";
    }

    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            int ptr = i;
            for(long long j = 0; j<805; j++){
                int nx = ne[ptr];
                int prv = pr[i];
                long long mi, ma;

                long long b = p[ptr] - p[i];
                long long a = p[i] - p[prv + 1];
                long long c = p[nx] - p[ptr];

                if(c < a) swap(a, c);

                //cout << ans << endl;

                mi = ((b + 2*j + 1) / (j + 1)) * (j + 1);
                mi = max(mi, 251*(j + 1));

                ma = ((b + a + j + 1) / (j + 1)) * (j + 1);

                if(ma >= mi){
                    ans += (((ma - mi) / (j  + 1) + 1) * (mi - (j + 1) - b + 1 + ma - (j + 1) - b + 1)) / 2;
                    //debug[j + 1] += (((ma - mi) / (j  + 1) + 1) * (mi - (j + 1) - b + 1 + ma - (j + 1) - b + 1)) / 2;
                }

                //cout << ans << endl;

                mi = ((b + a + j + 1) / (j + 1)) * (j + 1) + (j + 1);
                mi = max(mi, 251*(j + 1));

                ma = ((b + c + j + 1) / (j + 1)) * (j + 1);

                if(ma >= mi){
                    ans += ((ma - mi) / (j  + 1) + 1) * (a + 1);
                    //debug[j + 1] += ((ma - mi) / (j  + 1) + 1) * (a + 1);
                }

                //cout << ans << endl;

                mi = ((b + c + j + 1) / (j + 1)) * (j + 1) + (j + 1);
                mi = max(mi, 251*(j + 1));

                ma = ((b + a + c + j + 1) / (j + 1)) * (j + 1);

                if(ma >= mi){
                    ans += (((ma - mi) / (j + 1) + 1) * (b + (j + 1) + a + c - mi + 1 + b + a + (j + 1) + c - ma + 1)) / 2;
                    //debug[j + 1] += (((ma - mi) / (j + 1) + 1) * (b + (j + 1) + a + c - mi + 1 + b + a + (j + 1) + c - ma + 1)) / 2;
                }

                //cout << ans << endl;

                ptr = ne[ptr];

                if(ptr == n) break;
            }
        }
    }

    cout << ans << endl;
    /*for(int i = 0; i<10; i++){
        cout << debug[i] << " ";
    }*/


}