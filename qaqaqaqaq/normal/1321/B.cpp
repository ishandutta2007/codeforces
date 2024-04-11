#include<bits/stdc++.h>
using namespace std;

const int maxn=400007;
int n;
int a[maxn];
map<int,long long> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i<n;++i) s[a[i]-i]+=a[i];
    long long ans=0;
    for (auto c:s){
        ans=max(ans,c.second);
    }
    cout<<ans<<endl;
}