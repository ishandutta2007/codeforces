//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=40;
int a[N][N];
const int c=20;
int v[N];
int TOT=0;
void solve(){
    int L,R;cin>>L>>R;
//    vector<pair<pair<int,int>,int> >ans;
//    if (L==R){
//        cout<<"YES\n";
//        cout<<2<<" "<<1<<endl;
//        cout<<1<<" "<<2<<" "<<L<<endl;
//        return;
//    }
    int x=R-L+1;
//    if (L==1){
        int B=0;
        for (int i=0;i<20;i++){
            if (x&(1<<i)) B=i;
        }
        v[B]=1;
        TOT=2;
        for (int i=B-1;i>=0;i--) v[i]=++TOT;

        for (int i=B;i>=0;i--){
            for (int j=i-1;j>=0;j--){
                a[v[i]][v[j]]=(1<<j);
            }
            a[v[i]][32]=L;
        }
        int pref=(1<<B);
        a[v[B]][2]=1;
        for (int i=B-1;i>=0;i--){
            if (x&(1<<i)){

                a[2][v[i]]=pref-1;
                pref+=(1<<i);
            }
//            cout<<a[3][2]<<endl;
        }
        int m=0;
        for (int i=1;i<=32;i++){
            for (int j=i+1;j<=32;j++){
                if (a[i][j]) m++;
            }
        }
        cout<<"YES\n";
        cout<<32<<" "<<m<<endl;
        for (int i=1;i<=32;i++){
            for (int j=i+1;j<=32;j++){
                if (a[i][j]) cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            }
        }







//    }
//    if (__builtin_popcount(x)<=10){
//        int n=32;
//        for (int i=2;i<=c+1;i++){
//            for (int j=i+1;j<=c+1;j++){
//                a[i][j]=(1<<(c+1-i));
//            }
//            a[i][n]=(1<<(c+1-i));
//        }
//        int pref=0;
//        int cur=1;
//        int nw=c+2;
//        for (int i=c-1;i>=0;i--){
//            if (x&(1<<i)){
//
//                for (int j=c+2-i;j<=c+1;j++) a[cur][j]=L;
//                a[cur][n]=L;
//                a[cur][nw]=(1<<i);
//                cur=nw;
//
//                nw++;
//            }
//        }
//        int m=0;
//        for (int i=1;i<=n;i++){
//            for (int j=i+1;j<=n;j++){
//                if (a[i][j]) m++;
//            }
//        }
//        cout<<"YES\n";
//        cout<<c+2<<" "<<m<<endl;
//        for (int i=1;i<=n;i++){
//            for (int j=i+1;j<=n;j++){
//                if (a[i][j]) cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
//            }
//        }
//    } else {
//
//    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
3
a
a
b
*/