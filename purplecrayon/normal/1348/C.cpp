#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if (s[0]!=s[k-1]){
        cout<<s[k-1]<<endl;
        return;
    }
    cout<<s[0];
    if (s[k]!=s[n-1]){
        for (int i=k;i<n;i++)
            cout<<s[i];
    }
    else{
        for (int i=0;i<(n-k+k-1)/k;i++)
            cout<<s[n-1];
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}