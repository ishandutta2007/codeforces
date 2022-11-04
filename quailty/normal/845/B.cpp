#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[15];
    scanf("%s",s);
    int res=6;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                for(int l=0;l<10;l++)
                    for(int m=0;m<10;m++)
                        for(int n=0;n<10;n++)
                        {
                            if(i+j+k!=l+m+n)continue;
                            int cnt=0;
                            cnt+=(s[0]!=i+'0');
                            cnt+=(s[1]!=j+'0');
                            cnt+=(s[2]!=k+'0');
                            cnt+=(s[3]!=l+'0');
                            cnt+=(s[4]!=m+'0');
                            cnt+=(s[5]!=n+'0');
                            res=min(res,cnt);
                        }
    return 0*printf("%d\n",res);
}