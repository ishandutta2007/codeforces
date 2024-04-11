#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
void solve(){
    int a,b;cin>>a>>b;
    cout<<(abs(a-b)+9)/10<<endl;
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
7
10 10 8 5 3
*/