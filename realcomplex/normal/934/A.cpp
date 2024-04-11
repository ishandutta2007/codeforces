#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n,m;
    cin >> n >> m;
    ll a[n],b[m];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    for(int j = 0;j<m;j++)
        cin >> b[j];
    ll ans[n];
    for(int i = 0;i<n;i++){
        ans[i]=(ll)-1e18;
        for(int j = 0;j<n;j++){
            if(i==j)continue;
            for(int x = 0;x<m;x++){
                if(ans[i]<b[x]*a[j])
                    ans[i]=b[x]*a[j];
            }
        }
    }
    ll o = (ll)1e18;
    for(int i = 0;i<n;i++)o=min(o,ans[i]);
    cout << o << "\n";
    return 0;
}