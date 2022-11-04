#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct MC{
long long feet=0;
long long ele=0;
};
int main(){
    ios_base::sync_with_stdio(false);
    int n,c;
    cin>>n>>c;
    vector <int> a(n,0);
    vector <int> b(n,0);
    vector<MC>dp(n);
    dp[0].ele=c;
    for(int i=1;i<n;++i)cin>>a[i];
    for(int i=1;i<n;++i)cin>>b[i];
    cout<<0<<" ";
    for(int i=1;i<n;++i){
      dp[i].feet=min(a[i]+dp[i-1].feet,b[i]+dp[i-1].ele);
      cout<<dp[i].feet<<" ";
      long long tmp1=min(dp[i-1].ele+b[i],dp[i-1].feet+a[i]+c),tmp2=min(dp[i-1].ele+a[i]+c,dp[i-1].feet+b[i]+c);
      dp[i].ele=min(tmp1,tmp2);
    }

    return 0;
}