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

int main(){
    fastIO;
    int n,d;
    cin >> d >> n;
    string k;
    int ans = 0,cnt = 0;
    bool doi;
    for(int i = 0;i<n;i++){
        cin >> k;
        doi=false;
        for(auto x : k){
            if(x=='0')doi=true;
        }
        if(doi)cnt++,ans=max(ans,cnt);
        else cnt=0;
    }
    cout << ans << "\n";
    return 0;
}