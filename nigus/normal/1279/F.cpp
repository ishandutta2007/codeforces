#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;

int solve(vector<int> &a, int K, int L){
    vector<int> pref;
    pref.push_back(0);
    for(int c1 = 0; c1 < a.size(); c1++){
        pref.push_back(a[c1] + pref[c1]);
    }

    // sum of [i, j): pref[j] - pref[i]

    double l = 0;
    double r = 1e6+2;

    double ans = -1;
    for(int it = 0; it < 47; it++){
        double C = (l + r)/2.0;
        double DP[MAXN] = {0};
        int uses[MAXN] = {0};

        for(int n = 0; n <= int(a.size()); n++){
            if(n < L){
                DP[n] = 0.0;
                uses[n] = 0;
                if(pref[n] - C >= 0.0){
                    DP[n] = pref[n] - C;
                    uses[n] = 1;
                }
                continue;
            }

            DP[n] = DP[n-1];
            uses[n] = uses[n-1];
            if(pref[n] - pref[n-L] + DP[n-L] - C >= DP[n]){
                DP[n] = pref[n] - pref[n-L] + DP[n-L] - C;
                uses[n] = uses[n-L]+1;
            }
        }
        ans = DP[a.size()] + double(K) * C;
        if(uses[a.size()] == K){
            return round(ans);
        }
        if(uses[a.size()] > K){
            l = C;
        }
        else{
            r = C;
        }
    }
    return round(ans);
}

int main() {

    int n,k,l;
    string s;
    cin >> n >> k >> l;
    cin >> s;
    vector<int> a,b;
    int suma = 0;
    for(int c1 = 0; c1 < n; c1++){
        a.push_back((s[c1] >= 'a' && s[c1] <= 'z'));
        b.push_back((a[c1]^1));
        suma += a[c1];
    }

    int ans1 = suma - solve(a,k,l);
    int ans2 = n-suma - solve(b,k,l);

    cout << min(ans1, ans2) << "\n";


    return 0;
}