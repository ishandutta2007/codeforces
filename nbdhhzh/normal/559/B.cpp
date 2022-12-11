#include<bits/stdc++.h>
#define N 400010
using namespace std;
char s1[N],s2[N];
int i,j,k,t,ln;
int main()
{
    scanf("%s%s",s1,s2);
    ln=strlen(s1);
    for(t=ln;t%2==0;t/=2);
    for(i=t;i<ln;i<<=1)
    {
        for(j=0;j<ln;j+=i<<1)
        {
            for(k=0;k<i&&s1[j+k]==s1[j+i+k];k++);
            if(s1[j+k]>s1[j+i+k])
                for(;k<i;k++)swap(s1[j+k],s1[j+i+k]);
            for(k=0;k<i&&s2[j+k]==s2[j+i+k];k++);
            if(s2[j+k]>s2[j+i+k])
                for(;k<i;k++)swap(s2[j+k],s2[j+i+k]);
        }
    }
    for(i=0;i<ln;i++)if(s1[i]!=s2[i])break;
    if(i==ln)puts("YES");else puts("NO");
}