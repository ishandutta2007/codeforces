#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int a[2001][2001];
int b[2001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    int n=(int)s.size();
    int minx=1000001;
    for (int i=0;i<n;i++){
        if (minx>=(s[i]-'a')) cout<<"Mike\n";
        else cout<<"Ann\n";
        minx=min(minx,s[i]-'a');
    }
    return 0;
}