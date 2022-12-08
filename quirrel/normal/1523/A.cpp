#include<bits/stdc++.h>
using namespace std;
int L[1009], R[1009];
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        L[i] = m+1, R[i] = m+1;
    string s;
    cin >> s;
    int l = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') l = i;
        if(l != -1) L[i] = i - l;
    }
     l = n + 1;
     for(int i = s.size()-1; i >=0; i--){
        if(s[i] == '1') l = i;
        if(l != n + 1) R[i] = l - i;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '1' || (L[i] != R[i] && min(L[i], R[i]) <= m)) cout<<'1';
        else cout<<'0';
    }
    cout<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}