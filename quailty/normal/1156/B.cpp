#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char str[105];
        scanf("%s",str);
        int cnt[26]={0};
        for(int i=0;str[i];i++)
            cnt[str[i]-'a']++;
        vector<int> p;
        for(int i=0;i<26;i++)
            if(cnt[i])p.push_back(i);
        int tot=10000;
        while(tot-->0)
        {
            random_shuffle(p.begin(),p.end());
            bool isok=1;
            for(int i=0;i+1<(int)p.size();i++)
                isok&=(abs(p[i]-p[i+1])>1);
            if(isok)break;
        }
        if(tot<0)printf("No answer\n");
        else
        {
            for(auto &i:p)
                for(int j=0;j<cnt[i];j++)
                    printf("%c",'a'+i);
            printf("\n");
        }
    }
    return 0;
}