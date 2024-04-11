#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=200100;
const ll inf=1000000000000000001;
int n;
void solve(int l,int r,int cur){
    if (r-l==1){
        cout<<"! "<<l<<endl;
        return;
    }
    int m=(l+r)/2;
    int ask=n-m%n;
    cout<<"+ "<<ask<<endl;
    int ans;cin>>ans;
    if (ans==cur){
        r=m;
    } else {
        l=m;
    }
    solve(l+ask,r+ask,ans);
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    solve(1,n,0);

    return 0;

}

/**

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/