#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
stack<int>st;
char s[200005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    st.push(s[0]-'0');
    for(int i=1;i<n;i++)
    {
        if(!st.empty() && st.top()^1==s[i]-'0')st.pop();
        else st.push(s[i]-'0');
    }
    printf("%d\n",st.size());
    return 0;
}