#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>8
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),sum+=a[i];
    if(sum&1)return 0*printf("NO");
    bool isok=0;
    for(int _=0;_<2;_++)
    {
        set<ll> st;
        ll pre=0;
        for(int i=1;i<=n;i++)
        {
            st.insert(a[i]);
            pre+=a[i];
            isok|=(st.find(pre-sum/2)!=st.end());
        }
        reverse(a+1,a+n+1);
    }
    return 0*printf("%s",(isok ? "YES" : "NO"));
}