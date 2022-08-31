#include <bits/stdc++.h>
using namespace std;

int allone(int a[],int n)
{
    for(int i=0;i<n;i++) if(a[i]==0) return 0;
    
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,i,j;
    cin >> n >> m ;
  int a[m];
  int b[n];
  int count[m];
  
  
  for(i=0;i<m;i++) count[i]=0;
  for(i=0;i<n;i++) b[i]=0;

  int s=0;
  
  for(i=0;i<m;i++)
  {
   
    cin >> a[i];   
    b[a[i]-1]++;  
      
    count[ b[a[i]-1]-1]++;
    
    if(count[s] == n  ) 
    { 
    cout << 1;
     s++;
    }
    else cout << 0;
      
  }
    return 0;
}