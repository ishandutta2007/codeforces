#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int getPartialMatch(const string &N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while(begin + matched < m){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi[m-1];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s, t; cin >> s >> t;
    int c_s = 0, c_t = 0, c_p = 0;
    int n = (int)s.size(), m = (int)t.size();

    int p = getPartialMatch(t);

    for(int i=0;i<n;i++){
        if(s[i] == '1') c_s++;
    }

    for(int i=p;i<m;i++){
        if(t[i] == '1') c_p++;
    }

    for(int i=0;i<m;i++){
        if(t[i] == '1') c_t++;
    }

    int z_s = n - c_s, z_t = m - c_t, z_p = m - p - c_p;

    int ans = 0;
    if(c_s >= c_t && z_s >= z_t){
        cout << t;
        c_s -= c_t; z_s -= z_t;
    }

    while(c_s >= c_p && z_s >= z_p){
        for(int i=p;i<m;i++) cout << t[i];
        c_s -= c_p; z_s -= z_p;
    }

    for(int i=0;i<c_s;i++) cout << "1";
    for(int i=0;i<z_s;i++) cout << "0";
}