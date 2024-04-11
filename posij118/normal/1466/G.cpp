#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;
const long long a1 = 105461397;
const long long a2 = 487412337;

long long po(long long a, int e){
    if(e < 0) e += M - 1;

    if(e == 1) return a;
    if(e == 0) return 1;

    if(e % 2) return (a*po(a, e - 1)) % M;
    long long x = po(a, e/2);
    return (x * x) % M;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int st(string &s, string &t){
    if(t.size() > s.size()) return 0;
    string u = t + "#" + s;
    vector<int> v = prefix_function(u);
    int ret = 0;

    for(auto x: v){
        if (x == t.size()){
            ret++;
        }
    }

    return ret;

    /*
    vector<int> ret;

    int h1[s.size() + 1], h2[s.size() + 1], ht1[t.size() + 1], ht2[t.size() + 1];
    h1[0] = 0;
    h2[0] = 0;

    ht1[0] = 0;
    ht2[0] = 0;

    long long b1 = a1;
    long long b2 = a2;

    for(int i = 0; i<s.size(); i++){
        h1[i + 1] = (h1[i] + (s[i] - 'a')*b1) % M;
        h2[i + 1] = (h2[i] + (s[i] - 'a')*b2) % M;

        b1 = (b1 * a1) % M;
        b2 = (b2 * a2) % M;
    }

    b1 = a1;
    b2 = a2;

    for(int i = 0; i<t.size(); i++){
        ht1[i + 1] = (ht1[i] + (t[i] - 'a')*b1) % M;
        ht2[i + 1] = (ht2[i] + (t[i] - 'a')*b2) % M;

        b1 = (b1 * a1) % M;
        b2 = (b2 * a2) % M;
    }

    b1 = 1;
    b2 = 1;

    for(int i = 0; i<= s.size() - t.size(); i++){
        if(((ht1[t.size()] * b1) % M == (h1[i + t.size()] - h1[i] + M) % M)
           && ((ht2[t.size()] * b2) % M == (h2[i + t.size()] - h2[i] + M) % M)){
                ret.push_back(i);
        }

        b1 = (b1 * a1) % M;
        b2 = (b2 * a2) % M;
    }

    return ret;
    */
}

int main(){
    int n, q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    

    string test1 = "abbba";
    string test2 = "bb";
    //cout << st(test1, test2);

    string s0;
    cin >> s0;

    string s[100];
    s[0] = s0;

    string t;
    cin >> t;

    for(int i = 1; i<100; i++){
        s[i] = s[i - 1] + t[i - 1] + s[i - 1];
        if(s[i].size() > 2*1e6 + 5){
            break;
        }
    }

    long long p[n + 1][26];
    for(int i = 0; i<26; i++){
        p[0][i] = 0;
    }

    for(int i = 1; i<n + 1; i++){
        for(int j = 0; j<26; j++){
            if(t[i - 1] == 'a' + j){
                p[i][j] = p[i - 1][j] + po(2, -i + 1);
            }

            else{
                p[i][j] = p[i - 1][j];
            }
        }
    }

    while(q--){
        int x;
        cin >> x;

        string w;
        cin >> w;
        int maxi = -1;
        long long ans = 0;
        int cnt[26];
        fill(cnt, cnt + 26, 0);

        for(int i = 0; i<=x; i++){
            if(s[i].size() >= w.size()){
                maxi = i;
                int vec = st(s[i], w);
                ans += (vec * po(2, x - i)) % M;
                break;
            }
        }

        if(maxi == -1){
            cout << 0 << endl;
            continue;
        }

        for(char c = 'a'; c <= 'z'; c++){
            string sc;
            for(int i = s[maxi].size() - w.size() + 1; i<s[maxi].size(); i++){
                sc.push_back(s[maxi][i]);
            }
            sc.push_back(c);
            for(int i = 0; i<w.size() - 1; i++){
                sc.push_back(s[maxi][i]);
            }

            int vec = st(sc, w);
            cnt[c - 'a'] = vec;
        }

        for(int i = 0; i<26; i++){
            ans += (((cnt[i] * ((p[x][i] - p[maxi][i] + M) % M)) % M) * po(2, x - 1)) % M;
            ans %= M;
        }

        cout << ans << endl;
    }
}