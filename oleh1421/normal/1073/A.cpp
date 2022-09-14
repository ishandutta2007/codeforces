#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[400001];
ll s[400001];
ll s1[400001];
ll s2[400001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);int n;cin>>n;
    string s;cin>>s;
    for (int i=1;i<s.size();i++){
        if (s[i]!=s[i-1]) {cout<<"YES\n"<<s[i-1]<<s[i];return 0;}
    }
    cout<<"NO";
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/