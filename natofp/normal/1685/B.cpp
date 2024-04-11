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
#define mt make_tuple

using namespace std;

int a, b, c, d;
string s;
int n;

void solve(){
    cin >> a >> b >> c >> d;
    cin >> s;
    n = s.size();
    int cntA = 0;
    int cntB = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'A') cntA += 1;
        else cntB += 1;
    }
    if(cntA != a + c + d || cntB != b + c + d){
        cout << "NO" << "\n";
        return;
    }
    vector<int> ab, ba;
    int bonus = 0;
    for(int i=0;i<n;i++){
        int j = i;
        while(j + 1 < n && s[j + 1] != s[j]) j++;
        int len = j - i + 1;
        if(len >= 2){
            if(len % 2 == 1){
                bonus += len / 2;
            }
            else{
                if(s[i] == 'A') ab.pb(len / 2);
                else ba.pb(len / 2);
            }
        }
        i = j;
    }
    int mamC = 0;
    int mamD = 0;
    for(int x : ab) mamC += x;
    for(int x : ba) mamD += x;
    int need = max(0, c - mamC) + max(0, d - mamD);
    if(need <= bonus){
        cout << "YES" << "\n";
        return;
    }
    if(mamC < c && mamD < d){
        cout << "NO" << "\n";
        return;
    }
    sort(ab.begin(), ab.end());
    sort(ba.begin(), ba.end());
    reverse(ab.begin(), ab.end());
    reverse(ba.begin(), ba.end());
    if(mamC >= c){
        for(int x : ab){
            int canSac = mamC - c;
            if(canSac > 0){
                canSac -= 1;
                mamC -= 1;
                int lim = x - 1;
                int takeAway = min(lim, canSac);
                mamD += takeAway;
                canSac -= takeAway;
                mamC -= takeAway;
            }
        }
        int need = max(0, c - mamC) + max(0, d - mamD);
        if(need <= bonus) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        return;
    }
    else{
        for(int x : ba){
            int canSac = mamD - d;
            if(canSac > 0){
                canSac -= 1;
                mamD -= 1;
                int lim = x - 1;
                int takeAway = min(lim, canSac);
                mamC += takeAway;
                canSac -= takeAway;
                mamD -= takeAway;
            }
        }
        int need = max(0, c - mamC) + max(0, d - mamD);
        if(need <= bonus) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        return;
    }

    cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}