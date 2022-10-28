#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define author rajat1603
#define mod 1000000007
int arr[10000];
int n,N;
int ans=0;
int main(){
    cin>>n;
    N=1<<n;
    N<<=1;
    N-=2;
    for(int i=2;i<=N+1;++i){
        cin>>arr[i];
    }
    for(int i=n;i>=1;i--){
        int start = 1<<i;
        int end = (1<<(i+1))-1;
        for(int j=start;j<=end;j+=2){
            int mx = max(arr[j],arr[j+1]);
            int dif = abs(arr[j]-arr[j+1]);
            ans+=dif;
            arr[j/2]+=mx;
        }
    }
    printf("%d\n",ans);
}