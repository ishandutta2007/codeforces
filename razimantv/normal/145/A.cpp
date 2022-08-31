# include <cstdio>
# include <algorithm>

using namespace std;

int main()
{
    char a[100001],b[100001];
    scanf("%s%s",a,b);
    
    int fs=0,sf=0;
    for(int i=0;a[i];i++)
    {
        if(a[i]=='4'&&b[i]=='7')fs++;
        else if(a[i]=='7'&&b[i]=='4')sf++;
    }
    printf("%d\n",max(fs,sf));
    return 0;
}