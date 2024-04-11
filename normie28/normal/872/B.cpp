#include <bits/stdc++.h>
 
using namespace std;
 
int main (){
    int n,k,mx = -1000000007,mi = 1000000007,f,s; cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
	cin>>arr[i];
        mx = max(mx,arr[i]),mi = min(mi,arr[i]);
    }
    cout<<(k==1 ? mi : (k==2 ? max(arr[0],arr[n-1]) : mx));
}