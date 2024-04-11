#include<bits/stdc++.h>
using namespace std;
int a[1009];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> v = {1};
    cout<<1<<endl;
    for(int i = 2; i <= n; i++){
        if(a[i] == 1) v.push_back(1);
        else{
            while(v.back() != a[i] - 1)
                v.pop_back();
            v.back() ++;
        }
        for(int j = 0; j < v.size(); j++){
            cout << v[j];
            if(j == v.size()-1) cout<<endl;
            else cout<<'.';
        }
    }
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