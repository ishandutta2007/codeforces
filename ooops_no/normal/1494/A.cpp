#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int check(string s){
    int cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return 0;
    }
    return (cnt == 0);
}

bool solve(){
    string s;
    cin >> s;
    vector<char> a{'(', ')'};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                string t = "";
                for (int l = 0; l < s.size(); l++){
                    if (s[l] == 'A') t += a[i];
                    if (s[l] == 'B') t += a[j];
                    if (s[l] == 'C') t += a[k];
                }
                if (check(t)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        if (solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}