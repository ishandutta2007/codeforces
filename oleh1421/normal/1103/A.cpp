#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt0=0;
    int cnt1=0;
    string s;cin>>s;
    for (auto i:s){
        if (i=='0'){
            cnt0++;
            if (cnt0==5) cnt0=1;
            cout<<1<<" "<<cnt0<<endl;
        } else {
            cnt1++;
            if (cnt1==3) cnt1=1;
            cout<<3<<" "<<cnt1+cnt1-1<<endl;
        }
    }
    return 0;
}