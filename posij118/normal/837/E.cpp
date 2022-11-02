#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }

    return max(a, b);
}

int main(){
   long long int x, xx, y, d, cnt, maxi;
   cnt=0;
   cin >> x >> y;

   vector<long long int> div;
   xx=x;
   for(int i=2; i<sqrt(x)+1; i++){
        while(xx%i==0){
            div.push_back(i);
            xx/=i;
        }
   }

   if(xx>1) div.push_back(xx);
   bool div_used[div.size()];
   long long int div_next[div.size()];


    while(y>0){
            fill(div_used, div_used + div.size(), 0);
            d=gcd(x, y);
            for(int i=0; i<div.size(); i++){
                if(d%div[i]==0){
                    div_used[i]=1;
                    div_next[i]=0;
                    d/=div[i];
                }
            }
            d=gcd(x, y);
            for(int i=0; i<div.size(); i++){
                if(div_used[i]==0) div_next[i]=(y/(d*div[i]))*(d*div[i]);
            }
            maxi=0;
            for(int i=0; i<div.size(); i++){
                    maxi=max(maxi, div_next[i]);
            }
            cnt+=(y-maxi)/d;
            y=maxi;
    }

    cout << cnt;
}