#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p[109],d[109];
void solve(int l, int r, int h){
    if(l > r) return;
    int j = l;
    for(int i = l; i <= r; i++){
        if(p[i] > p[j]) j = i;
    }
    d[j] = h;
    solve(l, j-1, h+1);
    solve(j+1, r, h+1);

}
main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >>p[i];
        }
        solve(1,n,0);
        for(int i = 1; i <=n ; i++){
            cout<<d[i]<<" ";
        }
        cout<<endl;
    }


}