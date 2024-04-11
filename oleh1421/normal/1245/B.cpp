#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
void solve(){
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    int cnta=0;
    int cntb=0;
    int cntc=0;
    string s="";
    for (int i=1;i<=n;i++){
        char ch;cin>>ch;
        s+=ch;
        if (ch=='R') cnta++;
        if (ch=='P') cntb++;
        if (ch=='S') cntc++;
    }
    if (min(a,cntc)+min(b,cnta)+min(c,cntb)<(n+1)/2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (auto i:s){
        if (i=='R'){
            if (b>0) {
                cout<<'P';
                b--;
            } else if (c>cntb){
                cout<<'S';
                c--;
            } else {
                cout<<'R';
                a--;
            }
            cnta--;
        } else if (i=='P'){
            if (c>0) {
                cout<<'S';
                c--;
            } else if (b>cnta){
                cout<<'P';
                b--;
            } else {
                cout<<'R';
                a--;
            }
            cntb--;
        } else {
            if (a>0) {
                cout<<'R';
                a--;
            } else if (b>cnta){
                cout<<'P';
                b--;
            } else {
                cout<<'S';
                c--;
            }
            cntc--;
        }
    }
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}