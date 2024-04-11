#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int used[1001];
int main()
{
    int n;cin>>n;
    for (int i=0;i<n;i++){
        string s;cin>>s;
        used[s[0]-'a']++;
    }
    int res=0;
    for (int i=0;i<=int('z')-int('a');i++){
        int k=used[i]/2;
        int l=used[i]-k;
        res+=k*(k-1)/2;
        res+=l*(l-1)/2;
    }
    cout<<res;
    return 0;
}