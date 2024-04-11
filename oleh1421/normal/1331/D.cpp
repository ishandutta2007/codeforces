//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    int res=0;
    for (int i=1;i<s.size();i++){
        res*=10;
        res+=(s[i]-'0');
    }
    cout<<res%2;
    return 0;
}
/*
3 - 4
*/