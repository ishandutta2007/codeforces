#include<bits/stdc++.h>
#define MAXN 1000007
using namespace std;
long long a[MAXN],sum;
int n;
bool same[MAXN];
bool svj(long long x)
{
    long long rt=x;
    for(int i=1;i<n;i++)
    {
        if(!same[i-1]) x++;
        rt+=x;
        if(rt>=sum) return true;
    }
    return rt>=sum;
}
long long binarna(long long l,long long r)
{
    if(l==r) return l;
    long long s=(l+r)/2;
    if(svj(s)) return binarna(l,s);
    return binarna(s+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) sum+=a[i];
    stack<int> st;
    long long cur=a[0];
    for(int i=1;i<n;i++)
    {
        st.push(i-1);
        long long dif=a[i]-cur;
        while(!st.empty() && dif>=i-st.top())
        {
            dif-=(i-st.top()); st.pop();
            cur++;
        }
        if(!st.empty() && dif!=0)
        {
            int x=st.top(); st.pop();
            st.push(x+dif);
        }
        else
        {
            long long c=dif/(i+1LL);
            cur+=c;
            dif-=c*(i+1LL);
            if(dif>0) st.push(dif-1);
        }
    }
    while(!st.empty()) {same[st.top()]=true; st.pop();}
    long long p=binarna(0,1000000000000LL);
    for(int i=0;i<n;i++)
    {
        printf("%lld ",p);
        if(!same[i]) p++;
    }
}