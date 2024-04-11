#include<bits/stdc++.h>
typedef long long ll;
//#define endl '\n'

using namespace std;
const int N=200010;
const int A=10000001;
void solve(){
    int n,t;cin>>n>>t;
    while (t--){
        int k;cin>>k;
        int pos=0;
        for (int i=19;i>=0;i--){
            if (pos+(1<<i)>n) continue;
            cout<<"? "<<1<<" "<<pos+(1<<i)<<endl;
            int x;cin>>x;
            if (pos+(1<<i)-x<k) pos+=(1<<i);
        }
        cout<<"! "<<pos+1<<endl;
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 5 5
6 6 6 6 6
**/