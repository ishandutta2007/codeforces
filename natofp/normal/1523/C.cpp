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

const int nax = 1005;

vector<vector<int> > ans;

void solve(){
    ans.clear();
    int n; cin >> n;
    vector<int> chuj;
    int x; cin >> x;
    chuj.pb(x);
    assert(x == 1);
    ans.pb(chuj);
    for(int i=1;i<n;i++){
        int x; cin >> x;
        while(chuj.back() + 1 != x && x != 1){
            chuj.pop_back();
        }
        if(x==1)chuj.pb(x);
        else{
            chuj.pop_back();
            chuj.pb(x);
        }
        ans.pb(chuj);
    }
    for(auto x : ans){
        for(int i=0;i<x.size()-1;i++){
            cout << x[i] << ".";
        }
        cout<<x.back()<<"\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);



    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}