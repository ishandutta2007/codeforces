#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
char s[1001],ans[1001];
void add()
{
    for(int i=0;i<n;i++)
        s[i]=(s[i]-'0'+1)%10+'0';
}
void turn()
{
    char t[1001];
    t[0]=s[n-1];
    for(int i=1;i<n;i++){
        t[i]=s[i-1];
    }
    strcpy(s,t);
}
int main()
{
    scanf("%d%*c",&n);
    scanf("%s",s);
    strcpy(ans,s);
    for(int i=1;i<=10;i++){
        for(int j=1;j<=n;j++){
            if(strcmp(s,ans)<0)strcpy(ans,s);
            turn();
        }
        add();
    }
    ans[n]=0;
    printf("%s\n",ans);
    return 0;
}