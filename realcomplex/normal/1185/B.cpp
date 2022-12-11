#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

vector<pair<char ,int>> compr(string q){
    vector<pair<char ,int>> pp;
    int cnt = 0;
    char las = '!';
    for(auto p : q){
        if(p != las){
            if(cnt > 0)
                pp.push_back(mp(las, cnt));
            cnt = 1;
            las = p;
        }
        else{
            cnt ++ ;
        }
    }
    if(cnt > 0)
        pp.push_back(mp(las, cnt));
    return pp;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string s, t;
    bool ok;
    for(int h = 0 ; h  < n ; h ++ ){
        cin >> s >> t;
        vector<pair<char, int>> v1, v2;
        v1 = compr(s);
        v2 = compr(t);
        if(v1.size() == v2.size()){
            ok = true;
            for(int i = 0 ; i < v1.size(); i ++ ){
                if(v1[i].fi != v2[i].fi){
                    ok = false;
                }
                else{
                    if(v1[i].se > v2[i].se){
                        ok = false;
                    }
                }
            }
            if(ok)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}