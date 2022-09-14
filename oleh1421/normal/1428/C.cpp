#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define y1 y_1
void solve(){
    string s;cin>>s;
    int n=s.size();
    int del=0;
    int cnt=0;
    int B=0;
    for (int i=0;i<n;i++){
        if (s[i]=='B'){
            if (cnt) cnt--;
            else B++;
        } else {
            cnt++;
        }
    }
    cout<<B%2+cnt<<endl;
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