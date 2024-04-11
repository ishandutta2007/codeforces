#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    ll n,k;
    cin >> n >> k;
    ll m = n/k;
    if(m%2 == 0){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    return 0;
}