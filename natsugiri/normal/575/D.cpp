#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
//TEMPLATE {{{
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;

#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define all(c)           (c).begin(), (c).end()
#define perm(c)          sort(all(c)); for(bool _b = true; _b; _b = next_permutation(all(c)))
#define uniquenize(v)    (v).erase(unique(all(v)), (v).end())
#define sz(c)            int((c).size())

#ifdef HIBIKICHAN
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#else
#define dump(x)
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
inline int stoi(const string &s){return atoi(s.c_str());}
inline long long stoll(const string &s){return atoll(s.c_str());}

#endif

//}}}

int main(){
    vector<pair<int, int>> ans;
    for(int i = 1; i <= 1000; i++){ ans.push_back({i, 1}); ans.push_back({i, 2}); }
    for(int i = 1000; i >= 1; i--){ ans.push_back({i, 1}); ans.push_back({i, 2}); }

    cout << ans.size()/2 << endl;
    for(int i = 0; i < ans.size(); i += 2){
        cout << ans[i].first << " "  << ans[i].second << " "  << ans[i+1].first << " "  << ans[i+1].second << endl;
    }
}