#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int dp[500];
int a[5];
int main()
{
    dp[0] = 1;
    int sum = 0;
    for(int i = 0; i < 4; ++i){
        cin>>a[i]; sum += a[i];
        for(int j = 499; j >= a[i]; --j){
            if(dp[j-a[i]]) dp[j] = 1;
        }
    }
    if(sum&1){
        cout<<"NO"<<endl;
    }
    else if(dp[sum/2]){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}