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

int last[26];

void solve(){
    string s; cin >> s;
    for(int i=0;i<26;i++) last[i] = -1;
    int c = 0;
    for(char x : s){
        last[x - 'a'] = c;
        c++;
    }
    int gone = 0;
    while(1){
        if(last[s[gone] - 'a'] != gone) gone += 1;
        else break;
    }
    int n = s.size();
    for(int i=gone;i<n;i++) cout << s[i];
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}