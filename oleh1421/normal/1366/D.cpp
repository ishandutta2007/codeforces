//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=500010;
const int M=10000010;
int prime[M];
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=2;i<M;i++) prime[i]=i;
    for (int i=2;i*i<M;i++){
        if (prime[i]==i){
            for (int j=i*i;j<M;j+=i) prime[j]=i;
        }
    }
    vector<int>D1;
    vector<int>D2;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        int p=prime[x];
        int d1=1;
        while (x%p==0){
            d1*=p;
            x/=p;
        }
        if (x==1){
            x=-1;
            d1=-1;
        }
        D1.push_back(d1);
        D2.push_back(x);
    }
    for (auto i:D1) cout<<i<<" ";
    cout<<endl;
    for (auto i:D2) cout<<i<<" ";
    cout<<endl;
//    int tt;cin>>tt;
//    while (tt--){
//        solve();
//    }
    return 0;
}
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/