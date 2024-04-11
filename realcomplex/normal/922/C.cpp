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

set<int>check;

int main(){
    fastIO;
    ll n,k;
    cin >> n >> k;
    ll r = min(k,(ll)2e7);
    for(int i = 1;i<=(int)r;i++){
        if(check.count(n%i)){
            cout << "No\n";
            return 0;
        }
        check.insert(n%i);
    }
    cout << "Yes\n";
    return 0;
}