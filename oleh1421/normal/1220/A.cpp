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
    int n;cin>>n;
    string s;cin>>s;
    int cnt0=0;
    int cnt1=0;
    for (auto i:s){
        if (i=='z') cnt0++;
        else if (i=='n') cnt1++;
    }
    for (int i=0;i<cnt1;i++) cout<<"1 ";
    for (int i=0;i<cnt0;i++) cout<<"0 ";

    return 0;
}