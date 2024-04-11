//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000010;
int p[N];
int a[N],b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cout<<"? ";
        for (int j=1;j<=n;j++) {
            if (j==i) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
        cin>>a[i];
        cout<<"? ";
        for (int j=1;j<=n;j++) {
            if (j!=i) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
        cin>>b[i];
    }
    for (int i=n;i>=1;i--){
        if (a[i] && a[i]<i){
            b[a[i]]=i;
        }
        if (b[i] && b[i]<i){
            a[b[i]]=i;
        }
    }
    int one=1;
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            one=i;
            break;
        }
    }
    for (int it=1;it<=n;it++){
        p[one]=it;
        one=b[one];
    }
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;

//    int r=0;
//    for (int i=n;i>=1;i--){
//        if (p[i]) continue;
//        vector<int>v;
//        for (int j=1;j<n;j++){
//            cout<<"? ";
//            for (int t=1;t<=n;t++){
//                if (t==i) cout<<n-j<<" ";
//                else cout<<n-j+1<<" ";
//            }
//            cout<<endl;
//            int x;cin>>x;
//            if (p[x]){
//                p[i]=p[x]+j;
//                for (int t=0;t<v.size();t++) p[v[t]]=p[i]-t-1;
//                break;
//            } else if (x==0 || x==i) {
//
//            } else {
//                v.push_back(x);
//            }
//        }
//    }
}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
5
1
1
2
1
0
2
4
0
1
4

**/