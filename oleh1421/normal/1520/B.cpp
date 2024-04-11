#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=200010;
const int A=10000001;
void solve(){
    int n;cin>>n;
    int temp=1;
    int res=0;
    for (int len=1;len<=9;len++){
        for (int d=1;d<=9;d++){
            if (temp*d<=n) res++;
        }

        temp=temp*10+1;
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
/**
5 5 5
6 6 6 6 6
**/