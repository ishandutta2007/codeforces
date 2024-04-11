#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
bool ok(int a){
    int sum=0;
    while (a){
        sum+=a%10;
        a/=10;
    }
    if (sum%4==0) return true;
    else return false;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a;cin>>a;
    while(!ok(a)) a++;
    cout<<a;
    return 0;
}