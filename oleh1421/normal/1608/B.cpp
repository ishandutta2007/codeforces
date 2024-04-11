#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int p[N];
void solve(){
    int n,a,b;cin>>n>>a>>b;
    if (a*2+1>n || b*2+1>n || a+b+2>n || abs(a-b)>1){
        cout<<-1<<endl;
        return;
    }
    if (a==b+1){
        for (int i=1;i<=n;i++) p[i]=n-i+1;
        for (int i=1;i<=a;i++){
            swap(p[i*2-1],p[i*2]);
        }
    } else if (a+1==b){
        for (int i=1;i<=n;i++) p[i]=i;
        for (int i=1;i<=b;i++){
            swap(p[i*2-1],p[i*2]);
        }
    } else {
        for (int i=1;i<=n;i++) p[i]=i;
        for (int i=1;i<=a;i++){
            swap(p[i*2],p[i*2+1]);
        }
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
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

**/