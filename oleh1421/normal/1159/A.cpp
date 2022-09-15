#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    int minx=0;
    for (int i=0;i<n;i++){
        if (s[i]=='-') cnt--;
        else cnt++;
        minx=min(minx,cnt);
    }
    cout<<cnt-minx;
    return 0;
}