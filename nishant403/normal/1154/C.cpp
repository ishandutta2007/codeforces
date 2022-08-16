#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
int a[3];
f(i,3) cin >> a[i];
int x=min(min( a[0]/3,a[1]/2),a[2]/2);
a[0]-=x*3;
a[1]-=2*x;
a[2]-=2*x;
    
int ans=7*x;
int day[]={0,1,2,0,2,1,0};
int b[3]={0};
int aa=0;
    
f(i,7)    
{
    b[1]=a[1],b[2]=a[2],b[0]=a[0];
    int temp=0;
    f(j,6)
    {
        
        if( b[day[(i+j)%7]] <= 0 ) break;   
        else b[day[(i+j)%7] ]--;
        temp++;
    }
    aa=max(aa,temp);
}   
cout << ans +aa;    
}