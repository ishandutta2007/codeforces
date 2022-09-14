//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#define endl '\n'
typedef long long ll;
using namespace std;
mt19937 rnd(time(NULL));
const int Q=30000;
const int inf=1000000001;
const int N=50010;
int n,k;
int add(int a,int b){
    vector<int>v;
    while (a>0 || b>0){
        v.push_back((a%k+b%k)%k);
        a/=k;
        b/=k;
    }
    reverse(v.begin(),v.end());
    int res=0;
    for (int i:v) res=(res*k+i);
    return res;
}
int sub(int a,int b){
    vector<int>v;
    while (a>0 || b>0){
        v.push_back((a%k-b%k+k)%k);
        a/=k;
        b/=k;
    }
    reverse(v.begin(),v.end());
    int res=0;
    for (int i:v) res=(res*k+i);
    return res;
}
//int r[N];
void solve(){
    cin>>n>>k;
    int S=0;
    bool Plus=true;
//    for (int i=0;i<n;i++) r[i]=i;
    for (int i=0;i<n;i++){
//        i+z=S
        int z;
        if (Plus) z=add(S,i);
        else z=sub(S,i);
        cout<<z<<endl;
//        cout<<"Correct "<<r[2]<<" "<<r[i]<<endl;
        int ans;cin>>ans;
        if (ans) return;
        S=sub(z,S);
        Plus^=1;
//        for (int j=0;j<n;j++) r[j]=sub(z,r[j]);
//        0-2

//        r=sub(z,r);
    }

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//6
//20
//02
//5
/**
6 8
1 4
1 5
2 4
2 5
2 3
2 6
1 7
2 7
**/
//4 4
//1 2
//2 4
//1 4
//2 3
// 2 2 2 2 3 4 3 5
//
// 00000
// 01000
// 00011
// 00000
// 00000

//4 3
//4 9
//4 9
//4 9
//1 2
//
//? 2 3 4
//? 1 3 4
//? 1 2 4
//? 1 2 3