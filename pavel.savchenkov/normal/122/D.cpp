#include <cstdio>
#include <cstring>

using namespace std;

int main() {
 int n,k; scanf("%d%d\n",&n,&k);
 char s[n+6];s[0]=' ';
 for (int i=1;i<=n;i++)
 { scanf("%c",&s[i]);
   if (k==0) continue;
   if (s[i-2]=='4'&&s[i-1]=='7'&&s[i]=='7'&&(i-2)%2==1)
    {if (k%2==1) s[i-1]='4';k=0;} else 
      if (s[i-2]=='4'&&s[i-1]=='4'&&s[i]=='7'&&(i-2)%2==1)
       {if (k%2==1) s[i-1]='7';k=0;} else
        if (s[i-1]=='4'&&s[i]=='7')
         {if ((i-1)%2==0) s[i-1]='7'; else s[i]='4';k--;}
 }
 s[n+1]='\0';
 printf("%s",s);
 return 0;
 }