//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int a[N];
ll prefB[N],prefS[N];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,d,m;cin>>n>>d>>m;

    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v,u;
    for (int i=1;i<=n;i++){
        if (a[i]>m) v.push_back(a[i]);
        else u.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    reverse(v.begin(),v.end());
    reverse(u.begin(),u.end());
    int B=v.size(),S=u.size();
    for (int i=0;i<B;i++){
        prefB[i+1]=prefB[i]+v[i];
    }
    for (int i=0;i<S;i++){
        prefS[i+1]=prefS[i]+u[i];
    }
    ll res=prefS[S];
    for (int i=1;i<=B && (i-1)*d<=1000000000;++i){
        int ss=max((i-1)*d-(B-i),0);
        if (ss>S) continue;
        res=max(res,prefB[i]+prefS[S-ss]);
    }
    cout<<res<<endl;
    return 0;
}