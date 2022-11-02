#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

long long anss = 0;
string ans = "";
const int N = 1e5 + 10;
int tt[N];
vector<int> mp(1000);
int nnn;

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += tt[r];
    }
    return ans;
}

void inc(int i, int d){
    for (; i < nnn; i = (i | (i + 1))){
        tt[i] += d;
    }
}


long long distt(string s, string t){
    nnn = s.size();
    vector<int> a(s.size());
    vector<deque<int>> here(4);
    for (int i = 0; i < s.size(); i++){
        here[mp[s[i]]].pb(i);
    }
    for (int i = 0; i < t.size(); i++){
        a[i] = here[mp[t[i]]].front();
        here[mp[t[i]]].pop_front();
    }
    long long ans = 0;
    vector<int> sum(4);
    for (int i = 0; i < a.size(); i++){
        inc(a[i], 1);
        ans += (i + 1) - get(a[i]);
    }
    for (int i = 0; i < s.size(); i++){
        tt[i] = 0;
    }
    return ans;
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
    vector<char> v{'A', 'N', 'O', 'T'};
    mp['A'] = 0, mp['N'] = 1, mp['O'] = 2, mp['T'] = 3;
    while(t--){
        string s;
        cin >> s;
        vector<int> sum(4);
        for (auto to : s){
            sum[mp[to]]++;
        }
        vector<int> a{0, 1, 2, 3};
        anss = -1;
        do{
            string t = "";
            for (int i = 0; i < a.size(); i++){
                for (int j = 0; j < sum[a[i]]; j++){
                    t += v[a[i]];
                }
            }
            if (distt(t, s) > anss){
                anss = distt(t, s);
                ans = t;
            }
        }while(next_permutation(a.begin(), a.end()));
        cout << ans << "\n";
    }
    return 0;
}