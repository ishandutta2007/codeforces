#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N,arr[5000005], F[3][5000005];
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll total=0;
    for (int i=1; i<=N; i++){
        cin >> arr[i]; total+=arr[i];
    }
    if (total%3==0){
        total/=3;
        ll ct=0;
        ll ans=0;
        ll t=0;
        for (int i=1; i<=N-1; i++){
            t+=arr[i];
            if (t==2*total){
                ans+=ct;
            }
            if (t==total){
                ct++;
            }
        } 
        cout << ans << endl; 
    } else{
        cout << 0 << endl;
    }
}