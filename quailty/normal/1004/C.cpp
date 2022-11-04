#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],cnt[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    set<int> st;
    for(int i=n;i>=1;i--)
    {
        st.insert(a[i]);
        cnt[i]=(int)st.size();
    }
    st.clear();
    long long res=0;
    for(int i=1;i<=n;i++)
        if(st.find(a[i])==st.end())
        {
            st.insert(a[i]);
            res+=cnt[i+1];
        }
    printf("%lld\n",res);
    return 0;
}