#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

bool check(string s, string t){
    for (int i = 0; i + s.size() <= t.size(); i++){
        string rev = t.substr(i, s.size());
        reverse(rev.begin(), rev.end());
        if (t.substr(i, s.size()) == s || rev == s){
            bool f = 0;
            for (int j = i + s.size(); j < t.size(); j++){
                if (t[j] == '0'){
                    f = 1;
                }
            }
            for (int j = 0; j < i; j++){
                if (t[j] == '0'){
                    f = 1;
                }
            }
            if (f) continue;
            return 1;
        }
    }
    return 0;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    if (x == y){
        cout << "YES\n";
        return 0;
    }
    string s = "", t = "", ss = "1";
    for (int i = 0; i < 60; i++){
        if ((1LL << i) & x){
            s += '1';
        }
        else if (s.size() > 0){
            s += '0';
        }
        if ((1LL << i) & x){
            ss += '1';
        }
        else{
            ss += '0';
        }
    }
    for (int i = 0; i < 60; i++){
        if ((1LL << i) & y){
            t += '1';
        }
        else{
            t += '0';
        }
    }
    while(s.back() == '0') s.pop_back();
    while(t.back() == '0') t.pop_back();
    while(ss.back() == '0') ss.pop_back();
    if (check(s, t) || check(ss, t)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}