#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 100001;
int n;
int arr[N];
int main(){
    cin>>n;
    for(int i = 1; i <= n ; ++i){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    long long cur = 0;
    int ans = 0;
    for(int i = 1 ;i <= n ; ++i){
        if(arr[i]>=cur){
            cur+=arr[i];
            ans++;
        }
    }
    printf("%d\n",ans);
}