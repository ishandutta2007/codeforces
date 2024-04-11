#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define ld long double

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        map<char, int> cnt;
        for (auto to : a){
            cnt[to]++;
        }
        if (b != "abc" || min({cnt['a'], cnt['b'], cnt['c']}) == 0){
            for (int i = 0; i < cnt['a']; i++) cout << 'a';
            for (int i = 0; i < cnt['b']; i++) cout << 'b';
            for (int i = 0; i < cnt['c']; i++) cout << 'c';
        }
        else{
            for (int i = 0; i < cnt['a']; i++) cout << 'a';
            for (int i = 0; i < cnt['c']; i++) cout << 'c';
            for (int i = 0; i < cnt['b']; i++) cout << 'b';
        }
        for (char j = 'd'; j <= 'z'; j++){
            for (int i = 0; i < cnt[j]; i++){
                cout << j;
            }
        }
        cout << endl;
    }
    return 0;
}