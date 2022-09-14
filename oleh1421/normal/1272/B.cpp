#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    string s;cin>>s;
    int L,R,U,D;
    L=R=U=D=0;
    for (auto i:s){
        if (i=='L') L++;
        else if (i=='R') R++;
        else if (i=='U') U++;
        else D++;
    }
    L=min(L,R);
    R=L;
    U=min(U,D);
    D=U;
    if (L==0) U=min(U,1),D=min(D,1);
    if (U==0) L=min(L,1),R=min(R,1);
    cout<<(L+R+U+D)<<endl;
    for (int i=1;i<=L;i++) cout<<'L';
    for (int i=1;i<=U;i++) cout<<'U';
    for (int i=1;i<=R;i++) cout<<'R';
    for (int i=1;i<=D;i++) cout<<'D';
    cout<<endl;
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