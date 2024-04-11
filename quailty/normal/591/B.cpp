#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[200005];
int main()
{
    int n,m,p[26],q[26];
    scanf("%d%d%s",&n,&m,s);
    for(int i=0;i<26;i++)p[i]=i,q[i]=i;
    for(int i=0;i<m;i++)
    {
        char u[5],v[5];
        scanf("%s%s",u,v);
        swap(q[*u-'a'],q[*v-'a']);
        swap(p[q[*u-'a']],p[q[*v-'a']]);
    }
    for(int i=0;s[i];i++)
        printf("%c",p[s[i]-'a']+'a');
    return 0;
}