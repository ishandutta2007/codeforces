#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long

using namespace std;

const int mod=998244353;
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int n,m;
const int M=3001;
pair<int,int> dp[M][M],no={-1,-1};
int sumPoz,sumNeg;
vector<int> inv(2*M);
pair<int,int> calc(int a,int b)
{
    int wa=sumPoz+a,wb=sumNeg-b;
    if(a+b==m)
        return {wa,wb};
    if(dp[a][b]!=no)
        return dp[a][b];
    pair<int,int> A=calc(a+1,b),B=calc(a,b+1);
    A.f=mul(A.f,mul(wa,inv[a-b+m]));
    A.s=mul(A.s,mul(wa,inv[a-b+m]));
    B.f=mul(B.f,mul(wb,inv[a-b+m]));
    B.s=mul(B.s,mul(wb,inv[a-b+m]));
    return dp[a][b]={A.f+B.f,A.s+B.s};
}

int main()
{
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            dp[i][j]=no;
	scanf("%i %i",&n,&m);
	vector<int> a(n);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    vector<int> w(n);
    for(int i=0;i<n;i++)
        scanf("%i",&w[i]);
    for(int i=0;i<n;i++)
        if(a[i])
            sumPoz+=w[i];
        else
            sumNeg+=w[i];
    for(int i=0;i<2*m;i++)
    {
        int tr=sumPoz+sumNeg+i-m;
        if(tr<0)
            continue;
        inv[i]=powmod(tr,mod-2);
    }
    pair<int,int> sol=calc(0,0);
    sol.f=mul(sol.f,powmod(sumPoz,mod-2));
    sol.s=mul(sol.s,powmod(sumNeg,mod-2));
    for(int i=0;i<n;i++)
        if(a[i])
            printf("%i\n",mul(sol.f,w[i]));
        else
            printf("%i\n",mul(sol.s,w[i]));
}