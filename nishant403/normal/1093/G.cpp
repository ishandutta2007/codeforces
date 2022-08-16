#include <iostream>
using namespace std;
     
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
    
const int K = 32,N = 2e5+1,def = -1e8;

inline void wr (int n)
    {
    printf("%d\n",n);
    }

int st[2*N][K],a[N][5],n,k,q,typ,l,r,ix;  

void fastscan(int &number) 
{  
    scanf("%d",&number);
} 

void build()
{
  register int cur = 0;
    
  f(j,(1<<k))
  {      
  for(int i=n;i<2*n;i++) 
  {
   cur = 0;
             
   f(g,k) 
       if(j & (1<<g)) cur+=a[i-n][g];
       else cur-=a[i-n][g];
                  
           st[i][j] = cur;    
  }
     
   for(int i=n-1;i>=0;i--)
        st[i][j] = max(st[i<<1][j],st[i<<1^1][j]);  
  }
}
     
int query(int l,int r,int id)
{
  register int res = def;
        
for(l+=n,r+=n;l<r;l>>=1,r>>=1)
{
 if(l&1) res=max(res,st[l++][id]);   
 if(r&1) res=max(res,st[--r][id]);   
}
        
return res;
}
     
     
     
void upd(int index,int id)
{   
  register int cur = 0;
    
     f(i,k) 
         if((1<<i) & id) cur+=a[index][i];
         else cur-=a[index][i];
        
  for(st[index+=n][id] = cur; index > 1; index>>=1)
      st[index>>1][id] = max(st[index][id] , st[index^1][id]); 
         
}
     
int main()
{
    fast;
    fastscan(n);
    fastscan(k);
    
    f(i,n) f(j,k) fastscan(a[i][j]);
        
    build();
   
    fastscan(q);
    
    int res = def;
    
while(q--)
{

 fastscan(typ);
      
 if(typ==2)
 {
 fastscan(l);
 fastscan(r);
     
 l--;
                
 res = def;
                
 f(i,(1<<k)) res=max(res,abs( query(l,r,i)+query(l,r,i^((1<<k)-1))) ); 
             
 wr(res);    
}
            
 else
 {   
  fastscan(ix);
  ix--;   
                
  f(i,k) fastscan(a[ix][i]);
              
  f(i,(1<<k)) upd(ix,i);  
 }
 }        
}