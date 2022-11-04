#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
char str[MAXN];
int solve()
{
    scanf("%s",str);
    int n=strlen(str),res=1;
    set<char> st;
    for(int i=0;i<n;i++)
    {
        st.insert(str[i]);
        if(st.size()>3u)
        {
            st.clear(),res++;
            st.insert(str[i]);
        }
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}