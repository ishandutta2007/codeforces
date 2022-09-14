#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll mod=998244353;
int a[N],b[N];
void solve(){
    int n;cin>>n;
    int cntA=0,cntB=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
        cntA+=a[i];
    }
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        b[i]=(c-'0');
        cntB+=b[i];
    }
    if (cntA!=cntB && n-cntA+1!=cntB){
        cout<<-1<<endl;
        return;
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (a[i]!=b[i]){
            cnt++;
        }
    }
    int res=1000000001;
    if (cntA==cntB) res=cnt;
    if (n-cntA+1==cntB){
        for (int i=1;i<=n;i++){
            if (a[i]){
                int nw=(n-1)-(cnt-(a[i]!=b[i]))+(a[i]!=b[i]);
                res=min(res,nw+1);
            }
        }
    }
    cout<<res<<endl;

//    if (n%2 && xr){
//        cout<<-1<<endl;
//        return;
//    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

9
110010011



101101100


**/