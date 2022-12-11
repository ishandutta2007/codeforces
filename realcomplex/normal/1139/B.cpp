#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0 ; i < n ; i ++ )
        cin >> a[i];
    ll answ = 0;
    ll ls = (ll)1e10;
    for(int i = n-1; i >= 0 ; i -- ){
        if(a[i]<ls){
            answ += a[i];
            ls = a[i];
        }
        else if(a[i] >= ls){
            answ += max(0ll, ls - 1);
            ls = max(0ll,ls-1);
        }
    }
    cout << answ;
    return 0;
}