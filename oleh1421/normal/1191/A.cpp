#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    if (n%4==2){
        cout<<"1 B";
    } else if (n%4==1){
        cout<<"0 A";
    } else if (n%4==0){
        cout<<"1 A";
    } else cout<<"2 A";
    return 0;
}
//2 6 -2 -6  2