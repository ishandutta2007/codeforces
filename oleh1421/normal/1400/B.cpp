
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int get(int x,int y,int a,int b,int S){
    x=min(x,S/a);
    S-=x*a;
    y=min(y,S/b);
    S-=y*b;
    return x+y;
}
void solve(){
    int p,f;cin>>p>>f;
    int cntA,cntB,A,B;cin>>cntA>>cntB>>A>>B;
    if (A>B){
        swap(cntA,cntB);
        swap(A,B);
    }
    int res=0;
    for (int i=0;i<=cntA && i*A<=p;i++){
        int cur=i+min((p-i*A)/B,cntB)+get(cntA-i,cntB-min((p-i*A)/B,cntB),A,B,f);
        res=max(res,cur);
    }
    cout<<res<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}