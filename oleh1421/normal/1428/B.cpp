#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define y1 y_1
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    set<char>st;
    for (int i=0;i<n;i++){
        if (s[i]!='-') st.insert(s[i]);
    }
    if (st.size()==1){
        cout<<n<<endl;
        return;
    }
    int res=0;
    for (int i=0;i<n;i++){
        if (s[i]=='-' || s[(i+1)%n]=='-') res++;
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