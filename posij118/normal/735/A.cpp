#include <iostream>
using namespace std;

int main() {
int a;
int n, k, g, t;
cin >> n >> k;
char pole[n];
for(int i=0; i<n; i++){
   
   cin >> pole[i];
   if(pole[i]=='G') g=i;
   if(pole[i]=='T') t=i;
}

if((g-t)%k!=0) cout << "NO";

else {
   if(g>t){
       a=g;
       g=t;
       t=a;
   }
   for(int i=g; i<=t; i+=k) {
      if(pole[i]=='#') {
         cout << "NO";
         break;
      }
      if(i==t) cout << "YES";
   }
}



    return 0;
}