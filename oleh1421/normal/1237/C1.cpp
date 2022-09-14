#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
bool used[300001];
ll x[200001];
ll y[200001];
ll z[200001];
int32_t main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        int ind=i+1;
        while (used[ind]) ind++;
        if (ind>n) continue;
        ll dist=(x[i]-x[ind])*(x[i]-x[ind])+(y[i]-y[ind])*(y[i]-y[ind])+(z[i]-z[ind])*(z[i]-z[ind]);
        for (int j=i+2;j<=n;j++){
            if (used[j]) continue;
            ll cur=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
            if (cur<dist) ind=j,dist=cur;
        }
        cout<<i<<" "<<ind<<endl;
        used[i]=true;
        used[ind]=true;
    }

    return 0;
}
/*
11 4
WBWBWBBWBWBWBBWWBWB

*/