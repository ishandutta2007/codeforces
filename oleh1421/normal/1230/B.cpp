#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int a[101];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if (n==1){
        if (k==0) cout<<s;
        else cout<<0;
        return 0;
    }
    if (k==0){
        cout<<s;
        return 0;
    }
    if (s[0]!='1'){
        s[0]='1';
        k--;
    }
    for (int i=1;i<s.size() && k>0;i++){
        if (s[i]!='0'){
            s[i]='0';
            k--;
        }
    }
    cout<<s;
    return 0;
}