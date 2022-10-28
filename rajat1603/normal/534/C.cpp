#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
    int n;
    long long d;
    int arr[200001];
    cin>>n>>d;
    long long sum=0;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=1;i<=n;++i){
        long long x = max(1LL,d - (sum - arr[i]));
        long long y = min(arr[i]*1LL,d - (n-1))-x+1;
        cout<<arr[i] - y<<" ";
    }
}