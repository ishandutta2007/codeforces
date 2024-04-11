#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100001];
int b[100001];

int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int res=1;
    for (int i=1;i<=n;i++){
       // if (a[i]==a[i-1] && b[i]==b[i-1]) continue;
        res+=max(min(a[i],b[i])-max(a[i-1],b[i-1])+1-(a[i-1]==b[i-1]),0);
    }
    cout<<res;
    return 0;
}