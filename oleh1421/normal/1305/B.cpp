#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500010;
int a[N];
int b[N];
void solve(){
    string s;cin>>s;
    int i=-1;
    int j=-1;
    for (int t=0;t<s.size();t++){
        if (s[t]=='('){
            if (i==-1) i=t;
        } else j=t;
    }
    if (i==-1 || j==-1 || j<i){
        cout<<"0\n";
        return;
    }
    vector<int>v;
    vector<int>u;
    while (i<j){
        v.push_back(i);
        u.push_back(j);
        i++;
        j--;
        while (i<s.size() && s[i]==')') i++;
        while (j>=0 && s[j]=='(') j--;
    }
    reverse(u.begin(),u.end());
    cout<<1<<endl;
    cout<<v.size()*2<<endl;
    for (auto i:v) cout<<i+1<<" ";
    for (auto i:u) cout<<i+1<<" ";
    cout<<endl;
}
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}