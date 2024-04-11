#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int a[200001];
int b[200001];
int pos[200001];
int32_t main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    reverse(b+1,b+n+1);
    for (int i=1;i<=n;i++) pos[b[i]]=i;
    int minx=n+1;
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (minx<pos[a[i]]) cnt++;
        minx=min(minx,pos[a[i]]);
    }
    cout<<cnt;
    return 0;
}
/*
11 4
WBWBWBBWBWBWBBWWBWB

*/