#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,t,t1,u,v,a,b;
int arr[200001][2],brr[200001][2];
int main() {
    cin>>n;
    for (i=0;i<n;i++) cin>>arr[i][0];
    for (i=0;i<n;i++) cin>>arr[i][1];
    for (i=0;i<n;i++) cin>>brr[i][0];
    for (i=0;i<n;i++) cin>>brr[i][1];
    u=0; v=0; a=0;
    for (i=0;i<n;i++) {
        u+=arr[i][0]-brr[i][0];
        v+=arr[i][1]-brr[i][1];
        
        if (u*v<0) {
            a++;
            if (u>0) {
                u--; v++;
            }
            else {
                u++; v--;
            }
        }
        a+=abs(u); a+=abs(v);
    }
    if (u+v) cout<<-1; else cout<<a;
    
}