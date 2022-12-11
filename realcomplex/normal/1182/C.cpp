#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

vector<pii> wowel[128];

bool is(char t){
    return (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u');
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string s[n];
    int cnt;
    char last;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> s[i];
        cnt = 0;
        last = '-';
        for(auto p : s[i]){
            if(is(p)){
                last = p;
                cnt ++ ;
            }
        }
        wowel[last].push_back(mp(cnt, i));
    }
    vector<pii> pp;
    for(int i = 0 ; i < 128; i ++ )
        sort(wowel[i].begin(), wowel[i].end());
    for(int i = 0 ; i < 128; i ++ ){
        for(int j = 0; j < wowel[i].size(); j ++ ){
            if(wowel[i][j].fi == wowel[i][j-1].fi){
                pp.push_back(mp(wowel[i][j-1].se, wowel[i][j].se));
                wowel[i][j-1].se = -1;
                wowel[i][j].se = -1;
                j ++ ;
            }
        }
    }
    vector<pii> oth;
    for(int i = 0 ; i < 128; i ++ ){
        for(int j = 0 ; j < wowel[i].size(); j ++ ){
            if(wowel[i][j].se != -1)
                oth.push_back(wowel[i][j]);
        }
    }
    sort(oth.begin(), oth.end());
    vector<pii> sp;
    for(int i = 1; i < oth.size(); i ++ ){
        if(oth[i].fi == oth[i-1].fi){
            sp.push_back(mp(oth[i-1].se, oth[i].se));
            i ++ ;
        }
    }
    while(pp.size() > sp.size()){
        sp.push_back(pp.back());
        pp.pop_back();
    }
    cout << pp.size() << "\n";
    for(int i = 0 ; i < pp.size(); i ++ ){
        cout << s[sp[i].fi] << " " << s[pp[i].fi] << "\n";
        cout << s[sp[i].se] << " " << s[pp[i].se] << "\n";
    }
    return 0;
}