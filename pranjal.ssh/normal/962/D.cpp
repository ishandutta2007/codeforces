#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

map<ll, vector<int>> mp1;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    FOR(i, 1, n) {
        int temp; cin >> temp; mp1[temp].push_back(i);
    }
    vector<pair<ll,int>> finalAnswer;
    while (!mp1.empty()) {
        ll num = mp1.begin()->first;
        sort(mp1[num].begin(), mp1[num].end());
        reverse(all(mp1[num]));
        vi positions;
        while (mp1[num].size() > 1) {
            mp1[num].pop_back();
            int secondLast = mp1[num].back(); mp1[num].pop_back();
            positions.push_back(secondLast);
        }
        if (!mp1[num].empty()) {
            finalAnswer.push_back(make_pair(num, mp1[num][0]));
        }
        mp1.erase(mp1.begin());

        for (auto pos : positions) mp1[2LL * num].push_back(pos);

    }

    sort(all(finalAnswer), [](const pair<ll,int> &a, const pair<ll,int> &b) {
        return a.second < b.second;
    });
    cout << sz(finalAnswer) << "\n";
    for (pair<ll,int> t1 : finalAnswer) {
        cout << t1.first << " ";
    }
return 0;}