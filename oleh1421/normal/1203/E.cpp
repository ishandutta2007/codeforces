#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=150001;
bool used[N+10];
int a[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    used[0]=true;
    for (int i=1;i<=n;i++){
        if (!used[a[i]-1]) used[a[i]-1]=true;
        else if (!used[a[i]]) used[a[i]]=true;
        else used[a[i]+1]=true;
    }
    int cnt=0;
    for (int i=1;i<=N+1;i++) cnt+=used[i];
    cout<<cnt;
    return 0;
}