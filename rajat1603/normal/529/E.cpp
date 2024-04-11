#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define author rajat1603
#define N 5001
int arr[N];
bool cum[20000000]={0};
int main(){
    int n,K;
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        cum[arr[i]]=1;
    }
    int q;
    cin>>q;
    while(q--){
        int sum;
        cin>>sum;
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=K;j++){
                for(int k=0;k<=K-j;k++){
                    if(k==0&&arr[i]*j==sum){
                        ans=min(ans,j);
                    }
                    else if(k){
                        int left = arr[i]*j;
                        if(left<sum&&((sum-left)%k)==0){
                            int temp = sum-left;
                            temp/=k;
                            if(temp<=20000000){
                                if(cum[temp]&&temp!=arr[i]){
                                    ans=min(ans,j+k);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(ans==INT_MAX){
            printf("-1\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
}