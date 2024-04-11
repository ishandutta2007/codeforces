#include<bits/stdc++.h>
using namespace std;
const string prefix[4]={
    "52","05","57","00"
};
char str[25];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len=strlen(str);
        reverse(str,str+len);
        int res=len;
        for(int _=0;_<4;_++)
        {
            int now=0,j=0;
            for(int i=0;i<len && j<(int)prefix[_].size();i++)
            {
                if(prefix[_][j]==str[i])j++;
                else now++;
            }
            if(j==(int)prefix[_].size())res=min(res,now);
        }
        printf("%d\n",res);
    }
    return 0;
}