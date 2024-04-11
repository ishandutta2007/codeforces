#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
char s[MAXN];
int get(char x)
{
    if(x>='0' && x<='9')return x-'0';
    if(x>='A' && x<='Z')return x-'A'+10;
    if(x>='a' && x<='z')return x-'a'+36;
    return x=='-' ? 62 : 63;
}
int t[MAXN*6];
int main()
{
    scanf("%s",s);
    int n=strlen(s),res=1;
    for(int i=0;i<n;i++)
    {
        int tt=get(s[i]);
        for(int j=0;j<6;j++)
            if(~tt&(1<<j))res=1LL*res*3%Mod;
    }
    return 0*printf("%d",res);
}