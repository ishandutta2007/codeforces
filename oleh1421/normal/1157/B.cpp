#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int f[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string a;cin>>a;
    for (int i=1;i<=9;i++) cin>>f[i];
    int fi=-1;
    for (int i=0;i<n;i++){
        int cur=(a[i]-'0');
        if (f[cur]>cur){
            fi=i;
            break;
        }
    }
    if (fi==-1){
        cout<<a;
        return 0;
    }
    for (int i=fi;i<n;i++){
        int cur=(a[i]-'0');
        if (f[cur]<cur) break;
        a[i]=(f[cur]+'0');
    }
    cout<<a;
    return 0;
}