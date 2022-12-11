#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,t;
    cin >> n >> k >> t;
    if(t<=k){
        cout << t;
        exit(0);
    }
    if(t<=n){
        cout << k;
        exit(0);
    }
    cout << n+k-t;
    return 0;
}