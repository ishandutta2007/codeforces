#include<bits/stdc++.h>
using namespace std;
bool isv(char x)
{
    return x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='y';
}
char str[105];
int main()
{
    int n;
    scanf("%d%s",&n,str+1);
    for(int i=1,la=0;i<=n;i++)
        if(i==1 || !isv(str[i]) || !isv(str[la]))
            printf("%c",str[i]),la=i;
    return 0;
}