#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<k)return 0*printf("NO\n");
    multiset<int> st;
    for(int i=0;i<30;i++)
        if(n>>i&1)st.insert(1<<i);
    if((int)st.size()>k)printf("NO\n");
    else
    {
        while((int)st.size()<k)
        {
            int t=*(--st.end());
            st.erase(--st.end());
            st.insert(t>>1);
            st.insert(t>>1);
        }
        printf("YES\n");
        for(auto &t:st)
            printf("%d ",t);
    }
    return 0;
}