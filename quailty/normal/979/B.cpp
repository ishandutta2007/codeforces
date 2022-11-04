#include<bits/stdc++.h>
using namespace std;
const string cat[]={"Kuro","Shiro","Katie"};
char str[100005];
int main()
{
    int n;
    scanf("%d",&n);
    int res[3];
    for(int i=0;i<3;i++)
    {
        scanf("%s",str);
        int len=strlen(str),cnt[52]={0};
        for(int j=0;j<len;j++)
        {
            if(str[j]>='a' && str[j]<='z')cnt[str[j]-'a']++;
            else cnt[str[j]-'A'+26]++;
        }
        sort(cnt,cnt+52);
        if(cnt[51]<len)res[i]=min(cnt[51]+n,len);
        else res[i]=len-(n==1);
    }
    for(int i=0;i<3;i++)
        if(res[i]>res[(i+1)%3] && res[i]>res[(i+2)%3])
            return 0*printf("%s\n",cat[i].c_str());
    return 0*printf("Draw\n");
}