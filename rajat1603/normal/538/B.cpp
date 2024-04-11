#include<bits/stdc++.h>
using namespace std;
bool check(int n){
    while(n){
        int temp = n%10;
        if(temp>1){
            return 0;
        }
        n/=10;
    }
    return 1;
}
vector<int> v;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        if(check(i)){
            v.push_back(i);
        }
    }
    int *dp = new int[n+1];
    dp[0]=0;
    int *prev = new int [n+1];
    int x = v.size();
    for(int i=1;i<=n;++i){
        dp[i]=n+1;
        for(int j=0;j<x;++j){
            if(v[j]>i){
                break;
            }
            if(dp[i-v[j]]+1 < dp[i]){
                dp[i] = dp[i-v[j]]+1;
                prev[i] = v[j];
            }
        }
    }
    queue<int> lis;
    while(n){
        lis.push(prev[n]);
        n-=prev[n];
    }
    cout<<lis.size()<<"\n";
    while(!lis.empty()){
        cout<<lis.front()<<" ";
        lis.pop();
    }
}