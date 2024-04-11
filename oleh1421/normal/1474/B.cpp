//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300010;
mt19937 rnd(time(nullptr));
int a[N];
int cnt[1000100];
bool prime(int x){
    for (int i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}
void solve(){
    int d;cin>>d;
    int a=d+1;
    while (!prime(a)) a++;
    int b=a+d;
    while (!prime(b)) b++;
    cout<<(a*1ll)*(b*1ll)<<endl;


}
int32_t main()
{
//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

//4 1 2 3
//3 1 2 4
//2 1 3 4
//1 2 3 4
//2 3 1
//a[i]-a[i-1]+a[i-2]-a[i-3]+...