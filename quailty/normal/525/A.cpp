#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[200005];
int cnt[30];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int ans=0;
    for(int i=0;i<2*n-2;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            cnt[s[i]-'a']++;
        }
        else
        {
            if(cnt[s[i]-'A']>0)
            {
                cnt[s[i]-'A']--;
            }
            else ans++;
        }
    }
    printf("%d",ans);
    return 0;
}