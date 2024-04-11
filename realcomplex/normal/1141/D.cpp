#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> C[256], D[256];

int main(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> aq;
    vector<int> bq;
    for(int i = 0 ; i < a.size(); i ++ ){
        if(a[i] == '?') aq.push_back(i);
        else C[a[i]].push_back(i);
    }
    for(int i = 0 ;i < b.size(); i ++ ){
        if(b[i] == '?') bq.push_back(i);
        else D[b[i]].push_back(i);
    }
    vector<pii> answ;
    for(int i = 0 ; i < 256 ; i ++ ){
        while(!C[i].empty() && !D[i].empty()){
            answ.push_back(mp(C[i].back(), D[i].back()));
            C[i].pop_back();
            D[i].pop_back();
        }
    }
    for(int i = 0; i < 256; i ++ ){
        while(!aq.empty() && !D[i].empty()){
            answ.push_back(mp(aq.back(), D[i].back()));
            aq.pop_back();
            D[i].pop_back();
        }
    }
    for(int i = 0 ; i < 256; i ++ ){
        while(!C[i].empty() && !bq.empty()){
            answ.push_back(mp(C[i].back(), bq.back()));
            C[i].pop_back();
            bq.pop_back();
        }
    }
    while(!aq.empty() && !bq.empty()){
        answ.push_back(mp(aq.back(), bq.back()));
        aq.pop_back();
        bq.pop_back();
    }
    cout << answ.size() << "\n";
    for(auto x : answ)
        cout << x.fi + 1 << " " << x.se + 1<< "\n";
    return 0;
}