#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int main()
{
    int n,k,cnt[2]={0,0},res=0;
    scanf("%d%d%s",&n,&k,s);
    for(int l=0,r=0;l<n;cnt[s[l++]-'a']--)
    {
        while(r<=l || r<n)
        {
            cnt[s[r]-'a']++;
            if(min(cnt[0],cnt[1])>k)
            {
                cnt[s[r]-'a']--;
                break;
            }
            r++;
        }
        res=max(res,r-l);
    }
    printf("%d\n",res);
    return 0;
}