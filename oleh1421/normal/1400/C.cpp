
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;

void solve(){
    string s;cin>>s;
    int x;cin>>x;
    int n=s.size();
    string w="";
    for (int i=0;i<n;i++) w+="1";
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            if (i-x>=0) w[i-x]='0';
            if (i+x<n) w[i+x]='0';
        }
    }
    for (int i=0;i<n;i++){
        if (s[i]=='1' && (i+x>=n || w[i+x]=='0') && (i-x<0 || w[i-x]=='0')){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<w<<endl;

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