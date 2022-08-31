#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int BT = 22;
const int N = (1<<BT);
const int M = 1e6 + 10;

int arr[N];
int a[M];
int n;

signed main()
{
   fast;
    
   cin >> n;
    
   f(i,n) cin >> a[i];
   f(i,N) arr[i] = -1; 
   f(i,n) arr[a[i]] = a[i]; 
    
   f(i,BT) f(j,N) 
       if(j & (1<<i)) 
         if(arr[j] == -1) arr[j] = arr[j^(1<<i)];
        
   f(i,n) cout << arr[a[i]^(N-1)] << ' ';
}