#include <bits/stdc++.h>
#define MAXN 105
using namespace std;
char s[105];
int n,q,t,l,r;
int f[105][105];
bool flg;
int main()
{
 cin >> t;
 while(t--)
 {
  cin >> n >> q;
  scanf("%s",s+1);
  while(q--)
  {
   cin >> l >> r;
   memset(f , 0 , sizeof(f));
   for(int i = 0; i <= n; i++)
    f[i][0] = 1;
   for(int j = 1; j <= r - l + 1; j++)
    for(int i = 1; i <= n; i++)
    {
     if(s[i] == s[l + j - 1])
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
     else
      f[i][j] = f[i - 1][j];
    }
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
    flg=true;
    for(int j=0;j<=r-l;j++){
     if(s[i+j]!=s[l+j]){
      flg=false;
      break;
     }
    }
    if(flg)
     cnt++;
   }
   if(f[n][r-l+1]-cnt)
    puts("YES");
   else
    puts("NO");
  }
 }
    return 0;
}