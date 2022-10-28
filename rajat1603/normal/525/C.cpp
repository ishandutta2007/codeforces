#include <bits/stdc++.h>
using namespace std;
#define N 100001
#define pb push_back
int arr[N];
int v[N];
int n;
int x=0;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>arr[i];
    }
    sort(arr + 1, arr + n + 1);
    for (int i=n;i>1;i--){
        bool b = false;
        if (arr[i] == arr[i-1]){
            v[x++]=(arr[i]); 
            b = true;
        }
        else if (arr[i]==arr[i-1]+1){
            v[x++]=(arr[i-1]); 
            b=true;
        }
        if (b)i--;
    }
    long long ans = 0;
    for (int i = 0; i < x - 1; i += 2){
        ans += (long long) 1LL*v[i] * 1LL*v[i + 1];
    }
    cout<<ans;
}