#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
string s[nax];
int n;

void solve(){
    cin >> n;
    bool ok = false;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        if(s[i].size() == 1) ok = true;
        if(s[i].size() == 2 && s[i][0] == s[i][1]) ok = true;
        if(s[i].size() == 3 && s[i][0] == s[i][2]) ok = true;
    }
    if(ok){
        cout << "YES" << "\n";
        return;
    }
    set<string> all2;
    set<string> all3;
    for(int i=1;i<=n;i++){
        string cur = s[i];
        if(cur.size() == 2){
            string look = cur;
            reverse(look.begin(), look.end());
            if(all2.count(look) == 1) ok = true;
            string ac = look + "a";
            for(int i=0;i<26;i++){
                ac[2] = 'a' + i;
                if(all3.count(ac) == 1) ok = true;
            }
            all2.insert(cur);
        }
        else{
            string look = cur;
            reverse(look.begin(), look.end());
            if(all3.count(look) == 1) ok = true;
            string ac = "";
            ac += cur[2];
            ac += cur[1];
            if(all2.count(ac) == 1) ok = true;
            all3.insert(cur);
        }
    }
    if(ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}