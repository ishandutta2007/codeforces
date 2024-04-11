#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
int n;
vector<int> a(N);
vector<int> ans;

void func(int i){
    if (i + 2 >= n) return;
    int x = a[i] ^ a[i + 1] ^ a[i + 2];
    a[i] = a[i + 1] = a[i + 2] = x;
    ans.pb(i + 1);
}

void solve(){
    cin >> n;
    ans.clear();
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1 || *min_element(a.begin(), a.begin() + n) == 1){
        cout << "NO\n";
        return;
    }
    if (a[0] == 1){
        int i = 0;
        while(1){
            if (i + 2 >= n) break;
            int x = a[i] ^ a[i + 1] ^ a[i + 2];
            if (x == 0){
                for (int j = i; j >= 0; j -= 2){
                    func(j);
                }
                break;
            }
            if (a[i + 1] == 0){
                func(i);
            }
            i += 2;
        }
    }
    if (a[0] == 1){
        cout << "NO\n";
        return;
    }
    int i = 0;
    while(i < n){
        if (a[i] == 0){
            i++;
            continue;
        }
        if (a[i + 1] == 1){
            func(i - 1);
        }
        else{
            func(i);
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << ans.size() << endl;
    for (auto to : ans) cout << to << ' ';
    cout << endl;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}