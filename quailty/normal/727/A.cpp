#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
stack<int>st;
void dfs(int b,int a)
{
    if(b<a)return;
    st.push(b);
    if(b==a)
    {
        printf("YES\n");
        printf("%d\n",(int)st.size());
        while(!st.empty())
        {
            printf("%d ",st.top());
            st.pop();
        }
        exit(0);
    }
    if(b%10==1)dfs(b/10,a);
    if(b%2==0)dfs(b/2,a);
    st.pop();
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    dfs(b,a);
    return 0*printf("NO");
}