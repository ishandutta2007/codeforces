//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
bool ok(int i,int j,int t){
    cout<<2<<" "<<i<<" "<<j<<" "<<t<<endl;
    int x;cin>>x;
    return (x==1);
}
int area(int i,int j,int t){
    cout<<1<<" "<<i<<" "<<j<<" "<<t<<endl;
    int x;cin>>x;
    return x;
}
int32_t main()
{
    int n;cin>>n;
    int ind=2;
    for (int i=3;i<=n;i++){
        if (ok(1,i,ind)) ind=i;
    }
    vector<pair<int,int> >v;
    for (int i=2;i<=n;i++){
        if (i==ind) continue;
        v.push_back({area(1,ind,i),i});
    }
    sort(v.begin(),v.end());
    int right=v.back().second;
    vector<int>up;
    vector<int>down;
    for (int i=0;i+1<v.size();i++){
        if (ok(1,v[i].second,right)) down.push_back(v[i].second);
        else up.push_back(v[i].second);
    }
    vector<int>ans={1,ind};
    for (auto i:down) ans.push_back(i);
    ans.push_back(right);
    reverse(up.begin(),up.end());
    for (auto i:up) ans.push_back(i);
    cout<<0<<" ";
    for (auto i:ans) cout<<i<<" ";
    return 0;
}