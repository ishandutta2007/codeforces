#include<bits/stdc++.h>
using namespace std;
int a[1009];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << 3*n << endl;
    /*
    a b
    a+b b
    a+b -a
    b -a
    */
    for(int i = 1; i <= n; i+=2){
        cout << 1 << " " << i <<" "<<i+1<<endl;
        cout << 2 << " " << i <<" "<<i+1<<endl;
        cout << 1 << " " << i <<" "<<i+1<<endl;
        cout << 1 << " " << i <<" "<<i+1<<endl;
        cout << 2 << " " << i <<" "<<i+1<<endl;
        cout << 1 << " " << i <<" "<<i+1<<endl;
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