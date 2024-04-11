//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300010;
mt19937 rnd(time(nullptr));
int b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        b[i]=(c-'0');
    }
    string a="";
    int last=-1;
    for (int i=1;i<=n;i++){
        for (int j=2;j>=0;j--){
            if (last==j) continue;
            if (j-b[i]<0 || j-b[i]>1) continue;
            a+=char(j-b[i]+'0');
            last=j;
            break;
        }
    }
    cout<<a<<endl;

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