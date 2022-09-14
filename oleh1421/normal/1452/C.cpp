#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1010;

void solve(){
    string s;cin>>s;
    int x=0,y=0;
    int res=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='(') x++;
        else if (s[i]==')'){
            if (x>0){
                res++;
                x--;
            }
        }
        else if (s[i]=='[') {
            y++;
        }
        else {
            if (y>0){
                res++;
                y--;
            }
        }
    }
    cout<<res<<endl;

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
/*
1
][][
*/