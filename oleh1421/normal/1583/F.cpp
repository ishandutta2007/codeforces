//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=3010;
int a[N][N];
//int b[1010][1010];
int n,k,m;
int res=0;
void rec(int l,int r,int depth){
    res=max(res,depth);
    int len=r-l+1;
    if (len<=k){
        for (int i=l;i<=r;i++){
            for (int j=i+1;j<=r;j++) a[i][j]=depth;
        }
        return;
    }
    vector<int>v;
    for (int i=0;i<(len%k);i++) v.push_back(len/k+1);
    for (int i=len%k;i<k;i++) v.push_back(len/k);
    int cnt=0;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<cnt;j++){
            for (int t=0;t<v[i];t++){
                a[l+j][l+cnt+t]=depth;
            }
        }
        rec(l+cnt,l+cnt+v[i]-1,depth+1);
        cnt+=v[i];
    }
//    res=max(res,depth);
////    if (l*k+k-1>N) cout<<"OOOOOOOOOOOOK\n";
//    if (l==r){
////        cout<<"OOK\n";
//        for (int i=0;i<k;i++){
//            for (int j=0;j<k;j++){
//                a[l*k+i][l*k+j]=depth;
////                b[l*k+i][l*k+j]=depth;
////                cout<<depth<<" "<<l*k+i<<" "<<l*k+j<<endl;
//            }
//        }
//        return;
//    }
//    int mid=(l+r)/2;
//    rec(l,mid,depth+1);
//    rec(mid+1,r,depth+1);
//    for (int i=l*k;i<(mid+1)*k;i++){
//        for (int j=(mid+1)*k;j<(r+1)*k;j++){
//            a[i][j]=depth;
////            b[i][j]=depth;
//        }
//    }
}
void solve(){
    cin>>n>>k;
    rec(1,n,1);
    cout<<res<<endl;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++) {
            cout<<a[i][j]<<" ";
//            if (a[i][j]!=b[i][j]) exit(1);
        }
    }
    cout<<endl;
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