#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;

#define rep(i,a) for (ll i=0;i<a;i++)

void solve();

//  rainy ~  ~
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    rep(i,T) solve();
}

void solve(){
    string S,T;
    cin>>S>>T;
    int M=26;
    vector<int> p(M);
    rep(i,M) p[S[i]-'a']=i;
    int ans=0;
    rep(i,T.size()-1){
        ans+=abs(p[T[i+1]-'a']-p[T[i]-'a']);
    }
    cout<<ans<<"\n";
}