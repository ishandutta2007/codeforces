#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int mod=1e9+7;
const int maxn=100100;

int n,k;
ll s[maxn],lv[maxn],lv1[maxn];
char num[maxn];
ll ans;

ll C(int n,int r){
    if(r>n) return 0;
    if(r==0 || n==r) return 1;
    return ((lv[n]*lv1[r])%mod*lv1[n-r])%mod;
}

ll power(ll a,int k){
    ll ans=1;
    while(k){
        if(k&1) ans=ans*a%mod;
        k>>=1;a=a*a%mod;}
    return ans;
}

int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",num+1);
    for(int i=1;i<=n;i++)
        s[i]=(s[i-1]+num[i]-'0')%mod;
    lv[0]=1;
    for(int i=1;i<=n;i++)
        lv[i]=lv[i-1]*i%mod;
    lv1[n]=power(lv[n],mod-2);
    for(int i=n-1;i>=1;i--)
        lv1[i]=lv1[i+1]*(i+1)%mod;
    for(int l=0;l<n;l++){
        ans=(ans+(s[n-l-1]*C(n-l-2,k-1))%mod*power(10,l))%mod;
        ans=(ans+((num[n-l]-'0')*C(n-l-1,k))%mod*power(10,l))%mod;
    }
    printf("%I64d",ans);
    return 0;
}