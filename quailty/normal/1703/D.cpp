#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d",&n);
    vector<string> vec;
    set<string> st;
    for(int i=0;i<n;i++)
    {
        char s[15];
        scanf("%s",s);
        vec.emplace_back(s);
        st.insert(s);
    }
    for(int i=0;i<n;i++)
    {
        int isok=0;
        for(size_t j=1;j<vec[i].size() && !isok;j++)
        {
            string l=vec[i].substr(0,j),r=vec[i].substr(j);
            isok|=(st.count(l) && st.count(r));
        }
        printf("%d",isok);
    }
    return 0*printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}