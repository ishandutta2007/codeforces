#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
int main()
{
    int n,cnt[2]={0,0};
    scanf("%d%s",&n,s);
    for(int i=0;s[i];i++)
        cnt[s[i]=='A']++;
    if(cnt[0]>cnt[1])printf("Danik");
    else if(cnt[0]<cnt[1])printf("Anton");
    else printf("Friendship");
    return 0;
}