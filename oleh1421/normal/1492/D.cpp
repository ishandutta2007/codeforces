//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=1000000007ll;
const int A=1000100;

void solve(){
//    int n;cin>>n;
//    for (int x=0;x<(1<<n);x++){
//        for (int y=x;y<(1<<n);y++){
//            int A=__builtin_popcount(y);
//            int B=__builtin_popcount(x);
//            if (A!=B) continue;
//            int C=__builtin_popcount(y-x);
////            if (C>max(A,n-A)){
////                cout<<"OOK "<<x<<" "<<y<<endl;
////            }
//        }
//    }
    int a,b,k;cin>>a>>b>>k;
//    a=rand()%10;
//    b=rand()%10;
//    k=rand()%10;
//    cout<<a<<" "<<b<<" "<<k<<endl;
    swap(a,b);
    a--;
    int n=a+b;
    if (a==n || a==0){
        if (k) {
            cout<<"No\n";
            return;
        }
        cout<<"Yes\n";
        cout<<1;
        for (int i=1;i<=n;i++) cout<<(a>0);
        cout<<endl;
        cout<<1;
        for (int i=1;i<=n;i++) cout<<(a>0);
        cout<<endl;
        return;
    }
    if (k>=n){
        cout<<"No\n";
        return;
    }
    string A="",B="";
    for (int i=0;i<n;i++){
        A+="0";
        B+="0";
    }
    if (k<=a){
        for (int i=0;i<a-k;i++) A[i]=B[i]='1';
        for (int i=a-k;i<a;i++) A[i]=B[i+1]='1';
    } else {
//        cout<<"OOK\n"<<a<<" "<<k<<endl;
        for (int i=0;i<a;i++) A[i]=B[i]='1';
        B[0]='0';
        B[k]='1';
    }
    cout<<"Yes\n";
    cout<<"1"+A<<endl<<"1"+B<<endl;
//    ll x=0ll,y=0ll;
//    for (auto i:A){
//        x=(x*2ll+(i-'0'));
//    }
//    for (auto i:B){
//        y=(y*2ll+(i-'0'));
//    }
//    cout<<__builtin_popcount(x-y)<<endl;

}
int32_t main()
{
    srand(time(NULL));
//    freopen("subset.in","r",stdin);
//    freopen("subset.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*

4 3 5

*/