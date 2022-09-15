#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char a[101][101];
int main()
{
   int n;cin>>n;
   for (int i=0;i<=100;i++) for (int j=0;j<=100;j++) a[i][j]='#';
   for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin>>a[i][j];
   int cnt=0;
   for (int i=1;i<=n;i++){
       for (int j=1;j<=n;j++){
           cnt+=(a[i][j]=='.');
       }
   }
   if (cnt%5){
     cout<<"NO";
     return 0;
   }
   for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++){
          if (a[i][j]=='.'){
             if (a[i+1][j]=='.' && a[i+2][j]=='.' && a[i+1][j-1]=='.' && a[i+1][j+1]=='.'){
                 a[i+1][j]='#';
                 a[i+2][j]='#';
                 a[i+1][j-1]='#';
                 a[i+1][j+1]='#';
                 a[i][j]='#';
             } else {

              cout<<"NO";
              return 0;
             }
          }
      }
   }
for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (a[i][j]=='.') {
                cout<<"NO";
              return 0;
}
cout<<"YES";
   return 0;
}