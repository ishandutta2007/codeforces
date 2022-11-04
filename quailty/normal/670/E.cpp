#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<list>
#include<stack>
using namespace std;
const int MAXN=500005;
char s[MAXN],t[MAXN];
stack<int>stk;
list<int>lk;
typedef list<int>::iterator ptr;
int c[MAXN];
int main()
{
    int n,m,p;
    scanf("%d%d%d%s%s",&n,&m,&p,s+1,t+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')stk.push(i);
        else
        {
            c[i]=stk.top();
            c[stk.top()]=i;
            stk.pop();
        }
    }
    for(int i=1;i<=n;i++)
        lk.push_back(i);
    ptr r=lk.begin();
    for(int i=1;i<p;i++)r++;
    for(int i=1;i<=m;i++)
    {
        if(t[i]=='R')r++;
        if(t[i]=='L')r--;
        if(t[i]=='D')
        {
            ptr l=r;
            if(*r>c[*r])while(*l!=c[*r])l--;
            else while(*r!=c[*l])r++;
            while(l!=r)lk.erase(l++);
            lk.erase(r++);
            if(r==lk.end())r--;
        }
    }
    for(ptr itr=lk.begin();itr!=lk.end();itr++)
        printf("%c",s[*itr]);
    return 0;
}