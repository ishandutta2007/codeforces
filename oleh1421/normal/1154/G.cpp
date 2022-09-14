#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int used[10000001];
int N=10000000;
int arr[1000001];
int32_t main() {
    int n;cin>>n;
    pair<ll,pair<int,int> > res={1000000000000000001ll,{0,0}};
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        arr[i]=x;
        if (used[x]) res=min(res,{x,{used[x],i}});
        used[x]=i;
    }
    for (int i=1;i<=N;i++){
        int a=0,b=0;
        for (int j=i;j<=N;j+=i){
             if (!used[j]) continue;
             if (a){
                b=used[j];
                break;
             } else {
                a=used[j];
             }
        }
        if (a && b) res=min(res,{(arr[a]*arr[b])/i,{a,b}});
    }
    if (res.second.first>res.second.second) swap(res.second.first,res.second.second);
    cout<<res.second.first<<" "<<res.second.second;
    return 0;
}