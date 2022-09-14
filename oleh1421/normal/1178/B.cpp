#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[1000010];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    int n=(int)s.size();
    ll sum=0;
    for (int i=0;i<n-1;i++){
        if (s[i]=='v' && s[i+1]=='v') sum++;
    }
    ll cur=0;
    ll res=0ll;
    for (int i=0;i<n-1;i++){
        if (s[i]=='v' && s[i+1]=='v') cur++;
        if (s[i]=='o'){
            res+=cur*(sum-cur)*1ll;
        }
    }
    cout<<res;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/