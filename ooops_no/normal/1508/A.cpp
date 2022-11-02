#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void show_ans(string a, string b, char c){
    int i = 0, j = 0, x = 0;
    string s = "";
    while(i < a.size() || j < b.size()){
        if (i == a.size()) s += b[j++];
        else if (j == b.size()) s += a[i++];
        else{
            if (b[j] == c){
                j++;
                x++;
                continue;
            }
            if (b[j] != c && x == 0){
                s += b[j];
                j++;
            }
            else{
                if (a[i] == c) x--;
                x = max(x, 0ll);
                s += a[i];
                i++;
            }
        }
    }
    while(s.size() < a.size() + a.size() / 2){
        s += '0';
    }
    cout << s << endl;
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
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> v{a, b, c};
        vector<vector<int>> cnt(3, vector<int>(2));
        for (int i = 0; i < a.size(); i++){
            cnt[0][a[i] - '0']++;
        }
        for (int i = 0; i < b.size(); i++){
            cnt[1][b[i] - '0']++;
        }
        for (int i = 0; i < c.size(); i++){
            cnt[2][c[i] - '0']++;
        }
        bool x = 0;
        for (int i = 0; i < 3; i++){
            for (int j = i + 1; j < 3; j++){
                if (cnt[i][0] >= n && cnt[j][0] >= n){
                    if (cnt[i][0] >= cnt[j][0]){
                        show_ans(v[i], v[j], '0');
                    }
                    else{
                        show_ans(v[j], v[i], '0');
                    }
                    x = 1;
                    break;
                }
                else if (cnt[i][1] >= n && cnt[j][1] >= n){
                    if (cnt[i][1] >= cnt[j][1]){
                        show_ans(v[i], v[j], '1');
                    }
                    else{
                        show_ans(v[j], v[i], '1');
                    }
                    x = 1;
                    break;
                }
            }
            if (x) break;
        }
    }
    return 0;
}