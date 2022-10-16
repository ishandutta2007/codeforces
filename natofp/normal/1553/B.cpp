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


void solve(){
    string s; cin >> s;
    string t; cin >> t;

    int n = s.size();
    bool ac = false;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            bool dbg = (i == 0 && j == 2);
            int go = 0;
            bool ok = true;
            for(int k=i;k<=j;k++){
                if(s[k] == t[go]) go++;
                else{
                    ok = false;
                    break;
                }
            }
            if(ok && go <= t.size()){
                int need = t.size() - go;
                if(need > j){
                    ok = false;
                }
                else{
                    int done = 1;
                    while(go <= t.size()){
                        if(t[go] == s[j - done]){
                            go++;
                            done++;
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                }

                if(go == t.size()) ac = true;
                if(ok) ac = true;
            }
        }
    }
    if(ac) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}