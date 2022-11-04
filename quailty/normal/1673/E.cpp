#include<bits/stdc++.h>
using namespace std;
const int MAXL=1<<20;
const int MAXN=MAXL+5;
int b[MAXN],pw[MAXN],res[MAXN];
inline int binom(int n,int k)
{
    if(k<0 || k>n)return 0;
    return (n&k)==k;
}
int main()
{
    for(int i=(pw[0]=1);i<MAXN;i++)
        pw[i]=min(1LL*MAXN,2LL*pw[i-1]);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        int p=b[i];
        for(int j=i;j-i<=20 && j<=n;j++)
        {
            if(j>i)p=min(1LL*MAXL,1LL*p*pw[b[j]]);
            if(p>=MAXL)break;
            int pow_op=j-i,xor_op=(i>1)+(j<n);
            if(k>xor_op)res[p]^=binom(n-pow_op-xor_op-2,k-xor_op-1);
            else res[p]^=(n-1-pow_op-xor_op==0);
        }
    }
    int st=0;
    for(int i=0;i<MAXN;i++)
        if(res[i])st=i;
    for(int i=st;i>=0;i--)
        cout<<res[i];
    return 0;
}