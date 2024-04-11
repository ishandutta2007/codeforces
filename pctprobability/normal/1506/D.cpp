#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_set>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i, n) _rep2(i, 0, n)
#define _rep2(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using i64 = long long;
template<class T>
bool chmin(T& a, const T& b) { return (b < a) ? (a = b, true) : false; }
template<class T>
bool chmax(T& a, const T& b) { return (b > a) ? (a = b, true) : false; }
 
template<typename T>istream& operator>>(istream&i,vector<T>&v){rep(j,v.size())i>>v[j];return i;}
template<typename T>string join(vector<T>&v){stringstream s;rep(i,v.size())s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v){if(v.size())o<<join(v);return o;}
template<typename T>string join(vector<vector<T>>&vv){string s="\n";rep(i,vv.size())s+=join(vv[i])+"\n";return s;}
template<typename T>ostream& operator<<(ostream&o,vector<vector<T>>&vv){if(vv.size())o<<join(vv);return o;}
 
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<int> ans;
    while(t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        rep(i, n)
        {
            int a;
            cin >> a;
            mp[a]++;
        }
        int cnt = 0;
        for (auto [i, j]: mp)
        {
            chmax(cnt, 2 * j - n);
        }
        if (cnt == 0 && n & 1) cnt++;
        ans.push_back(cnt);
    }
    for (auto i: ans) cout << i << "\n";
}