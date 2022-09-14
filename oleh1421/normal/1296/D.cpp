#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;
#define endl '\n'
const int N=200010;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a,b,k;cin>>n>>a>>b>>k;
    vector<int>v;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        x%=(a+b);
        if (!x) x=a+b;
        v.push_back((x+a-1)/a - 1);
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for (auto i:v){
        if (i>k) break;
        k-=i;
        cnt++;
    }
    cout<<cnt;
    return 0;
}