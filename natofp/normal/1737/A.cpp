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

int cnt[26];

void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    fill(cnt, cnt + 26, 0);
    for(char x : s) cnt[x - 'a'] += 1;
    string ans = "";
    for(int i=0;i<k;i++){
        int ile = n / k;
        char mex = 'a';
        for(int j=0;j<26;j++){
            if(cnt[j]){
                cnt[j] -= 1;
                mex++;
                ile--;
                if(ile == 0) break;
            }
            else break;
        }
        ans += mex;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}