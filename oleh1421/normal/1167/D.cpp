#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int s1[200001];
int s2[200001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<n;i++) a[i+1]=2*(s[i]=='(')-1;
    s[0]=0;
    for (int i=1;i<=n;i++){
        s1[i]=s1[i-1]+(a[i]==1);
    }
    for (int i=1;i<=n;i++){
        s2[i]=s2[i-1]+(a[i]==-1);
    }
    for (int i=1;i<=n;i++){
        if (a[i]==1) cout<<s1[i]%2;
        else cout<<s2[i]%2;
    }
    return 0;
}
//2 6 -2 -6  2