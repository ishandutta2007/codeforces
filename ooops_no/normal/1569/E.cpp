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

const int MOD = 998244353;

vector<int> d, dd{1, 2, 3, 5, 9, 17};
vector<pair<int,vector<pair<int,int>>>> win, loss;

int mul(int a, int b){
    return (a * b % MOD);
}

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void gen(vector<int> a, vector<pair<int,int>> ans, int now, int sum, bool f){
    if (a.size() == 1){
        ans.pb({a[0], dd[now - f]});
        sum = add(sum, mul(d[now - f], a[0]));
        if (!f) win.pb({sum, ans});
        else loss.pb({sum, ans});
    }
    else{
        int n = a.size() / 2;
        for (int i = 0; i < (1 << n); i++){
            vector<int> b;
            auto anss = ans;
            int summ = sum;
            for (int j = 0; j < n; j++){
                if (i & (1 << j)){
                    b.pb(a[j * 2 + 1]);
                    summ = add(summ, mul(d[now], a[j * 2]));
                    anss.pb({a[j * 2], dd[now]});
                }
                else{
                    b.pb(a[j * 2]);
                    summ = add(summ, mul(d[now], a[j * 2 + 1]));
                    anss.pb({a[j * 2 + 1], dd[now]});
                }
            }
            gen(b, anss, now - 1, summ, f);
        }
    }
}

int k, a, h;

void check(){
    sort(win.begin(), win.end());
    sort(loss.begin(), loss.end());
    int r = 0;
    for (int i = 0; i < win.size(); i++){
        while(r + 1 < loss.size() && win[i].first + loss[r + 1].first <= h){
            r++;
        }
        if (win[i].first + loss[r].first == h){
            vector<int> ans(1 << k);
            for (auto to : win[i].second){
                ans[to.first - 1] = to.second;
            }
            for (auto to : loss[r].second){
                ans[to.first - 1] = to.second;
            }
            for (auto to : ans){
                cout << to << ' ';
            }
            exit(0);
        }
    }
    r = 0;
    for (int i = (int)(win.size()) - 1; i >= 0; i--){
        while(r + 1 < loss.size() && win[i].first + loss[r + 1].first - MOD <= h){
            r++;
        }
        if (win[i].first + loss[r].first - MOD == h){
            vector<int> ans(1 << k);
            for (auto to : win[i].second){
                ans[to.first - 1] = to.second;
            }
            for (auto to : loss[r].second){
                ans[to.first - 1] = to.second;
            }
            for (auto to : ans){
                cout << to << ' ';
            }
            exit(0);
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> a >> h;
    for (auto to : dd){
        int now = 1;
        for (int i = 0; i < to; i++){
            now = mul(now, a);
        }
        d.pb(now);
    }
    if (k <= 4){
        vector<int> v(1 << k);
        iota(v.begin(), v.end(), 1);
        gen(v, vector<pair<int,int>>{}, k, 0, 0);
        for (auto to : win){
            if (to.first == h){
                vector<int> ans(1 << k);
                for (auto t : to.second){
                    ans[t.first - 1] = t.second;
                }
                for (auto to : ans){
                    cout << to << ' ';
                }
                return 0;
            }
        }
        cout << -1 << endl;
    }
    else{
        vector<int> v(1 << (k - 1));
        iota(v.begin(), v.end(), 1);
        gen(v, vector<pair<int,int>>{}, k, 0, 1);
        iota(v.begin(), v.end(), (1 << (k - 1)) + 1);
        gen(v, vector<pair<int,int>>{}, k, 0, 0);
        check();
        win.clear();
        loss.clear();
        iota(v.begin(), v.end(), 1);
        gen(v, vector<pair<int,int>>{}, k, 0, 0);
        iota(v.begin(), v.end(), (1 << (k - 1)) + 1);
        gen(v, vector<pair<int,int>>{}, k, 0, 1);
        check();
        cout << -1 << endl;
    }
    return 0;
}