//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const int N=100010;
int a[N];
void solve(){
    int n,x;cin>>n>>x;
    int ind=-1;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]%=x;
    int res=-1;
    int sum=0;
    for (int i=1;i<=n;i++){
        sum+=a[i];
        sum%=x;
        if (sum) res=max(res,i);
        else {
            if (ind!=-1) res=max(res,i-ind);
        }
        if (ind==-1 && a[i]) ind=i;
    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
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