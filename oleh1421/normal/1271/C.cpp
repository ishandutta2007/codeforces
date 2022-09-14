#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
//int x[300001];
//int y[300001];
void solve(){
    int n,sx,sy;cin>>n>>sx>>sy;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int cnt4=0;
    for (int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        if (x>sx) cnt1++;
        if (x<sx) cnt2++;
        if (y>sy) cnt3++;
        if (y<sy) cnt4++;
    }
    int res=max({cnt1,cnt2,cnt3,cnt4});
    cout<<res<<endl;
    if (cnt1==res){
        cout<<sx+1<<" "<<sy<<endl;
    } else if (cnt2==res){
        cout<<sx-1<<" "<<sy<<endl;
    } else if (cnt3==res){
        cout<<sx<<" "<<sy+1<<endl;
    } else {
        cout<<sx<<" "<<sy-1<<endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}