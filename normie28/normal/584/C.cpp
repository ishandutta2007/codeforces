#include <bits/stdc++.h>
using namespace std;
char a[100001], b[100001], s[100001];
char dif(char i, char j)
{
   for(int c='a'; c<='z'; c++) if(c!=i && c!=j) return c;
}
int main()
{
   int n, t, i;
   cin>>n>>t;
   scanf("%s", a);
   scanf("%s", b);
   int same=0, diff=0;
   for(i=0; i<n; i++) {
      if(a[i]==b[i]) same++;
      else diff++;
   }
   if(t>=diff) {
      int d=0;
      for(i=0; i<n; i++) {
         if(a[i]==b[i]) {
            if(d<t-diff) {
               s[i]=dif(a[i],b[i]);
               d++;
            }
            else s[i]=a[i];
         }
         else s[i]=dif(a[i],b[i]);
      }
   }
   else if((n-t)<=diff/2+same) {
      int sa=0, sb=0;
      for(i=0; i<n; i++) {
         if(a[i]==b[i]) s[i]=a[i];
         else if(sa<n-t-same) {
            s[i]=a[i]; sa++;
         }
         else if(sb<n-t-same) {
            s[i]=b[i]; sb++;
         }
         else s[i]=dif(a[i],b[i]);
      }
   }
   else strcat(s,"-1");
   puts(s);
}