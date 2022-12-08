#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >>s;
        for(int j = 1; j <= n; j++){
            if(s[j-1] == 'a') a[i][j] = 1;
            if(s[j-1] == 'b') a[i][j] = 2;
        }
    }
    if(m % 2 == 1){
        cout<<"YES"<<endl;
        for(int i = 1; i <= m + 1; i++)
            cout << i%2+1<<" ";
            cout<<endl;
        return;
    }
    if(n == 2 && a[1][2] != a[2][1]){
         cout<<"NO"<<endl;
         return;
    }
    cout <<"YES"<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i][j] == a[j][i]){
                for(int x = 1; x <= m+1; x++){
                    cout << (x % 2 ? i : j) <<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    int x,y,z;
    if(a[1][2] == a[2][3]) x=1,y=2,z=3;
    if(a[2][3] == a[3][1]) x=2,y=3,z=1;
    if(a[3][1] == a[1][2]) x=3,y=1,z=2;
    if(m % 4 == 2){
    
        for(int i = 1; i <= m/4; i++)
            cout<<x<<" "<<y<<" "<<z<<" "<<y<<" ";
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    else{
        cout<<y<<" ";
          for(int i = 1; i <= m/4; i++)
            cout<<x<<" "<<y<<" "<<z<<" "<<y<<" ";
        cout<<endl;
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