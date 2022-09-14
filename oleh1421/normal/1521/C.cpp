#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=200010;
const ll mod=1000000007;
int pos=-1;
void solve(){
    int n;cin>>n;
    pos=-1;
    for (int i=1;i<n;i+=2){
        cout<<"? "<<2<<" "<<i<<" "<<i+1<<" "<<1<<endl;
        int ans;cin>>ans;
        if (ans==1){
            pos=i;
            break;
        } else if (ans==2){
            cout<<"? "<<2<<" "<<i+1<<" "<<i<<" "<<1<<endl;
            int ans;cin>>ans;
            if (ans==1){
                pos=i+1;
                break;
            }
        }
    }
    if (n%2){
        int i=n-1;
        cout<<"? "<<2<<" "<<i<<" "<<i+1<<" "<<1<<endl;
        int ans;cin>>ans;
        if (ans==1){
            pos=i;
        } else if (ans==2){
            cout<<"? "<<2<<" "<<i+1<<" "<<i<<" "<<1<<endl;
            int ans;cin>>ans;
            if (ans==1){
                pos=i+1;
            }
        }
    }
    vector<int>ans;
    for (int i=1;i<=n;i++){
        if (i==pos) {
            ans.push_back(1);
            continue;
        }
        cout<<"? "<<1<<" "<<pos<<" "<<i<<" "<<n-1<<endl;
        int x;cin>>x;
        ans.push_back(x);
    }
    cout<<"! ";
    for (int i:ans) cout<<i<<" ";
    cout<<endl;


}
int32_t main()
{
//    cout<<mod<<endl;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
9
1 2
3 4
2 4
2 5
1 6
4 7
6 8
6 9

*/