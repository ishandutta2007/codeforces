#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
 int n,i,j, answer=0,sum,mi=101;
 bool ar[101]={false};
 
 
 cin >> n ;
 
 for(i=1;i<=n;i++) 
 {
     cin >> j;
     mi=min(mi,j);
     answer+=j;
     ar[j]=1;
 }
 
 
 sum=answer;
 
 for(j=100;j>=4;j--)
 {
     if(ar[j]==0) continue;
         
         for(i=2;i<=j/2;i++)
             if(j%i==0)    answer=min(answer,sum-j-mi+(mi*i)+(j/i));
         
 }
 
 cout << answer;
 return 0;
}