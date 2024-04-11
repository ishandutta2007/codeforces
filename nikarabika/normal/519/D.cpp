#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<char, long long int>, int> myp;
typedef long long int ll;
#define MP make_pair
#define X first
#define Y second
#define PB push_back

const int maxn = 1e5 + 10;
ll em[26];
ll PS[maxn];
vector<myp> a;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 26; i++)
        cin >> em[i];
    cin >> s;
    PS[0] = 0;
    a.PB(MP(MP(s[0], PS[0] + em[s[0]-'a']), 0));
    for(int i = 1; i < s.size(); i++){
        PS[i] = PS[i - 1] + em[s[i - 1]-'a'];
        a.PB(MP(MP(s[i], PS[i] + em[s[i]-'a']), i));
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        vector<myp>::iterator it = lower_bound(a.begin(), a.end(), MP(MP(s[i], PS[i]), i));
        ll st = it - lower_bound(a.begin(), a.end(), MP(MP(s[i], PS[i]), 0));
        ans += st;
    }
    cout << ans << endl;
    return 0;
}