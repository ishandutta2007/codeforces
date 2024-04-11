#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define y1 y_1
void solve(){
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    if (x1==x2){
        cout<<abs(y2-y1)<<endl;
    } else if (y1==y2){
        cout<<abs(x2-x1)<<endl;
    } else {
        cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
    }

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