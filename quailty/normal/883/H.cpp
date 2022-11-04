#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[400010];
int num[200];
int n;
vector<char> vec;
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;++i) num[s[i]]++;
    int ans=0,pr=0;
    for(int i=0;i<150;++i)
    {
        if(num[i]&1)
        {
            --num[i];
            ++ans;
            vec.push_back((char)i);
        }
        pr+=num[i]/2;
    }
    if(ans==0)
    {
        vector<char> tem;
        printf("1\n");
        for(int i=0;i<150;++i)
        {
            while(num[i]>0)
            {
                tem.push_back((char)i);
                num[i]-=2;
                putchar((char)i);
            }
        }
        for(int i=(int)tem.size()-1;i>=0;--i) putchar(tem[i]);
        puts("");
        return 0;
    }
    while(pr%ans)
    {
        for(int i=0;i<150;++i)
        if(num[i]>0)
        {
            ans+=2;
            vec.push_back((char)i);
            vec.push_back((char)i);
            num[i]-=2;
            --pr;
            break;
        }
    }
    int len=pr/ans;
    printf("%d\n",ans);
    for(auto &ch:vec)
    {
        vector<char> tem;
        int now=len;
        for(int i=0;now>0 && i<150;++i)
        if(num[i]>0)
        {
            while(num[i]>0 && now>0)
            {
                putchar((char)i);
                tem.push_back((char)i);
                num[i]-=2;
                --now;
            }
        }
        putchar(ch);
        for(int i=(int)tem.size()-1;i>=0;--i) putchar(tem[i]);
        --ans;
        if(ans>0) putchar(' ');
        else puts("");
    }
    return 0;
}