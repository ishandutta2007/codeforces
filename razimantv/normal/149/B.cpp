# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;

char num[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int conv[128];

bool ret(char *a,int b,int lim)
{
    int ret=0;
    for(int i=0;a[i];i++)
    {
        if(conv[a[i]]>=b)return false;
        ret=ret*b+conv[a[i]];
    }
    return ret<lim;
}

int main()
{
    for(int i=0;num[i];i++)
        conv[num[i]]=i;
    
    char a[10],b[10];
    cin.getline(a,10,':');
    cin.getline(b,10);
    
    if(ret(a,60,24)&&ret(b,60,60))
    {
        printf("-1\n");
        return 0;
    }
    
    int cnt=0;
    for(int i=2;i<60;i++)
    {
        if(ret(a,i,24)&&ret(b,i,60))
        {
            printf("%d ",i);
            cnt++;
        }
    }
    if(cnt==0)printf("0");
    printf("\n");
    return 0;
}