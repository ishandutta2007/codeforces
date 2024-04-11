#include <bits/stdc++.h>
 
using namespace std;
using ll =long long;
 
ll dp[1<<19][105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string s;
    int m,i,j,k;
    cin>>s>>m;
    
    ll fac[20];
    fac[0]=1;
    for(i=1;i<20;i++){
        fac[i]=fac[i-1]*i;
    }
    dp[0][0]=1;
    
    int sz=s.size();
    for(i=0;i<(1<<sz);i++){
        for(j=0;j<m;j++){
            for(k=0;k<sz;k++){
                if(i==0 && s[k] == '0'){
                    continue;
                }
                
                if(i&(1<<k))   continue;       
                    dp[(i|(1<<k))][(j*10 + s[k]-'0') % m]+=dp[i][j];
            }
        }
    }
    
    int f[100]={0};
    for(i=0;i<sz;i++)
        f[s[i]-'0']++;
    for(i=0;i<10;i++){
        dp[(1<<sz)-1][0]/=fac[f[i]];
    }
    cout<<dp[(1<<sz)-1][0];
}