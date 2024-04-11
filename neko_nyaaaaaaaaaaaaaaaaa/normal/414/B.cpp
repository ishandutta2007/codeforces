#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
long long n,k,dp[2001][2001]={0},Ti=0;
const long long mod=1000000007;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++) dp[i][j]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            for(int q=i;q<=n;q+=i){
                dp[q][j]+=dp[i][j-1]%mod;
                dp[q][j]%=mod;
            }
        }
    }
    for(int i=1;i<=n;i++) Ti+=dp[i][k],Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}