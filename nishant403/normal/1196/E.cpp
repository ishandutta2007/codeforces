#include <iostream>
#include <cstdio>
using namespace std;

#define f(n) for(int i=1;i<=n;i++)

int flag=0,t=1,b,w;

void go(int i,int j)
{
 printf("%d %d\n",i+flag,j);   
}
 
void solve()
{
flag = 0;    
    
scanf("%d %d",&b,&w);
    
if(w > b)
{
 swap(w,b);
 flag = 1;   
}
   
if(3*w + 1 < b) { printf("NO\n"); return; }
   
    printf("YES\n");
    
    f(w) go(2*i,4);
    f(w) go(2*i+1,4);
    
    int rem = b - w;
    
    if(rem == 0) return;
    
    go(1,4);
    
    rem--;
    
    if(rem == 0) return;
    
    f(min(w,rem)) go(2*i,3);
    
    rem-=min(w,rem);
    
    if(rem==0) return;
    
    f(min(w,rem)) go(2*i,5);
}
 
int main()
{
    scanf("%d",&t);   
    while(t--) solve();   
}