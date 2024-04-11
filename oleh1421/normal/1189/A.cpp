#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    int sum=0;
    for (auto i:s) sum+=(i-'0');
    if (sum*2==n){
        cout<<2<<endl;
        cout<<s[0]<<" ";
        for (int i=1;i<n;i++) cout<<s[i];
        return 0;
    }
    cout<<1<<endl;
    cout<<s;
    return 0;
}