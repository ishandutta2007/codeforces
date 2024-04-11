#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n;
    int a[n];
    rep(i, n)
        cin>>a[i];
    cin>>m;
    int b[m];
    rep(i, m)
        cin>>b[i];
    sort(a, a+n);
    sort(b, b+m);
    int jj=0;
    int ans=0;
    rep(i, n){
        FOR(j, jj, m-1){
            if(abs(a[i]-b[j])<=1){
                jj=j+1;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}