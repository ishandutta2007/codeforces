#include <bits/stdc++.h>
 
using namespace std;
 
#define linf 2000000000000000000LL
#define bit(mask,i) ((mask>>i)&1)
 
const int max_bit = 63;
 
long long C[max_bit+1][max_bit+1];
 
int bcount(long long x){
    int res = 0;
    for (;x;x&=(x-1)) res++;
    return res;
}
long long solve(long long x,int k){
            long long res = (k == bcount(x));
            for (int i = max_bit; i >= 0 && k>=0; i -- )
             if (bit(x,i)) 
              res+=C[i][k--];
            return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    C[0][0] = 1;
    for (int i = 1; i <= max_bit ;i ++ )
     for (int j = 0 ; j <= i ; j ++ )
      C[i][j]=C[i-1][j]+((j)?(C[i-1][j-1]):0);
 
    long long count;
    int k;
    cin>>count>>k;
 
    
    long long l = 1 , r = linf/2;
    while (l<r)
    {
          long long m = l + (r-l)/2;
          if (solve(m*2,k)-solve(m,k)<count) l = m+1;
          else
           r = m;
    }
    
    cout<<l;
    return 0;
}