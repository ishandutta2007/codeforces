#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

ll cnt(string cur){
    int n=cur.size();
    ll sh=0;
    for(auto x : cur)
        if(x=='h')sh++;
    ll ans = 0;
    for(auto x :cur){
        if(x=='h')sh--;
        else ans += sh;
    }
    return ans;
}

bool comp(string a,string b){
    return (cnt(a+b) > cnt(b+a));
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string t[n];
    for(int i = 0;i<n;i++)
        cin >> t[i];
    sort(t,t+n,comp);
    string ri;
    for(int i = 0;i<n;i++)ri += t[i];
    cout << cnt(ri);
    return 0;
}