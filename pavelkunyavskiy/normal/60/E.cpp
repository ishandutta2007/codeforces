#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

const int MATRSIZE=2;

struct matrix{
  vector<vector<int> > m;
  inline matrix()
  {
    m.resize(MATRSIZE,vector<int> (MATRSIZE,0));
  }
  inline matrix(int a,int b,int c,int d)
  {
    m.resize(MATRSIZE,vector<int> (MATRSIZE,0));
    m[0][0]=a;
    m[0][1]=b;
    m[1][0]=c;
    m[1][1]=d;
    
  }
  inline vector<int>& operator[](int a)
  {
    return m[a];
  }                              
  inline const vector<int>& operator[] (int a) const
  {
    return m[a];
  }                              

};

int p;
       

matrix operator*(const matrix& a,const matrix& b)
{
  matrix res;
  for (int i=0;i<MATRSIZE;i++)
    for (int j=0;j<MATRSIZE;j++)
      for (int k=0;k<MATRSIZE;k++)
        res[i][j]=(a[i][k]*1LL*b[k][j]+res[i][j])%p;    
  return res;
}

matrix operator^(const matrix& a,int64 b)
{
  if (b==1)
    return a;
  if (b==0)
    return matrix(1,0,0,1);
  if (b%2==0)
  {
    matrix tmp=a^(b/2);
    return tmp*tmp;
  }
  return (a^(b-1))*a; 
}

int a[1100000];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    int64 x,y;
    cin>>n>>x>>y>>p;
    int sum=0;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum=(sum+a[i])%p;
    }
    if (n==1){  
        printf("%d\n",sum);
        return 0;
    }
    matrix msum(3,(p*2-a[0]-a[n-1])%p,0,1);
    matrix mmax(1,1,1,0);
    matrix tmp=msum^x;
    sum=(tmp[0][0]*1LL*sum+tmp[0][1])%p;
    tmp=mmax^x;
    a[n-1]=(tmp[0][0]*1LL*a[n-1]+tmp[0][1]*1LL*a[n-2])%p;
    msum=matrix(3,(p*2-a[0]-a[n-1])%p,0,1);
    tmp=msum^y;
    sum=(tmp[0][0]*1LL*sum+tmp[0][1])%p;
    cout<<sum<<endl;
    return 0;
}