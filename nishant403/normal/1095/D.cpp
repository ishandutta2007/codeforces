#include <bits/stdc++.h>
using namespace std;
int main()
{

int n;
cin >> n ;

int a[n+1][2];
bool boolf[n+1]={false};
for(int i=1;i<=n;i++) cin >> a[i][0] >> a[i][1];

//solve it here 
int p,q;
int ans[n+1];
ans[1]=1;
boolf[1]=true;
for(int i=2;i<=n;i++)
{
p=a[ans[i-1]][0] ;
q=a[ans[i-1]][1] ;
    
    
if(boolf[p]==false && ( a[p][0]==q || a[p][1]==q)) 
{
    ans[i]=p;
     boolf[p]=true;   
}
 else 
 {
     ans[i]=q;   
    boolf[q]=true;
     
 }
}

for(int i=1;i<=n;i++) cout << ans[i] << " ";



return 0;
}