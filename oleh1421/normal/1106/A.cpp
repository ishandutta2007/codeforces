#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char a[500][500];
int main()
{
   int n;cin>>n;
   for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin>>a[i][j];
   int cnt=0;
   for (int i=1;i<n-1;i++){
       for (int j=1;j<n-1;j++){
            if (a[i][j]==a[i-1][j-1] && a[i][j]==a[i+1][j+1] && a[i][j]==a[i+1][j-1] && a[i][j]==a[i-1][j+1] && a[i][j]=='X') cnt++;
       }
   }
   cout<<cnt;
   return 0;
}