// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, d, r, pocetd, pocetr, c, cmod, dmod, rmod, a;
 c=-1;
 d=0;
 r=0;
  cin >> n;
pocetd =0;
pocetr =0;

  char strany[n];
  bool pouzito[n];
 
  for(int i=0; i<n; i++){
      cin >> strany[i];
  }
  
  for(int i=0; i<n; i++){
     pouzito [i] =0;
  }
for(int i=0; i<n; i++){
    if(strany[i]=='D') pocetd++;
    else pocetr++;
}

 while(pocetd>0 && pocetr>0){
     c++;
     cmod=c%n;
     
     if(strany[cmod]=='D' && pouzito[cmod]==0){
         pocetr--;
         
         if(pocetr>0){
         do{
         if(r<c){
            r=c; 
         }
         a=0;
         r++;
         rmod=r%n;
         if(strany [rmod]=='R' && pouzito [rmod]==0){
            pouzito [rmod] =1;
            a++;
         }
             
         }
         while(a==0);
         }
     }
    
    else if(strany[cmod]=='R' && pouzito[cmod]==0){
         pocetd--;
         
         if(pocetd>0){do
         {
         if(d<c){
            d=c; 
         }
         d++;
         dmod =d%n;
         a=0;
         if(strany [dmod]=='D' && pouzito [dmod]==0){
            pouzito [dmod] =1;
            a++;
         }
             
         }
         while(a==0);
         }
     }
     
 }
 
 if(pocetr ==0) cout << "D";
 else cout << "R";
 
}