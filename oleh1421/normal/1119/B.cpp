#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int maxx[300001];
int minx[300001];
int a[300001];
int main()
{
    int n,h;cin>>n>>h;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int k=2;k<=n;k++){
        vector<int>v;
        for (int i=1;i<=k;i++){
            v.push_back(a[i]);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        v.push_back(0);
        ll cur=0ll;
        for (int i=0;i<k;i+=2){
            cur+=max(v[i],v[i+1])*1ll;
            if (cur>h) break;
        }
        if (cur>h){
            cout<<k-1;
            exit(0);
        }
    }
    cout<<n;
    return 0;
}