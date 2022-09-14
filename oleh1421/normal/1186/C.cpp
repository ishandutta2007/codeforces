#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int s[2000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;cin>>str;
    for (int i=0;i<(int)str.size();i++){
        s[i+1]=s[i]+(str[i]=='1');
    }
    string b;cin>>b;
    int k=(int)b.size();
    int sum=0;
    for (auto i:b) sum+=(i=='1');
    int res=0;
    for (int i=k;i<=str.size();i++){
        res+=(s[i]-s[i-k]+sum+1)%2;
    }
    cout<<res;
    return 0;
}