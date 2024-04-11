#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
bool used[300001];
void solve(){
    vector<int>v;
    string t;cin>>t;
    string s="";
    for (int i=0;i<=t.size();i++) used[i]=false;
    for (int i=2;i+2<t.size();i++){
        if (t[i]=='o' && t[i+1]=='n' && t[i+2]=='e' && t[i-2]=='t' && t[i-1]=='w'){
            v.push_back(i);
            used[i]=true;
            used[i+1]=true;
            used[i+2]=true;
            used[i-1]=true;
            used[i-2]=true;
        }
    }
    for (int i=0;i<t.size();i++){
        if (used[i]) continue;
        if ((t[i-1]=='o' && t[i]=='n' && t[i+1]=='e') || (t[i-1]=='t' && t[i]=='w' && t[i+1]=='o')) v.push_back(i);
    }
    cout<<v.size()<<endl;
    for (auto i:v) cout<<i+1<<" ";
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}