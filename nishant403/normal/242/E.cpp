#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int BT = 20;
const int N = 1e5+10;
const int BLOCK = 250;

bitset<BT> a[N];
long long pw[BT];
int data[N/BLOCK][BT];
int tag[N/BLOCK][BT];

void build(int n)
{
    f(i,n) f(j,BT) data[i/BLOCK][j]+=a[i][j];
}

void push(int id)
{
    f(i,BT)
    {
        if(tag[id][i] == 0) continue;
        
        for(int j=(id*BLOCK);j<(id+1)*BLOCK;j++)
        {
            a[j][i]=a[j][i]^1;
        }
        
        tag[id][i] = 0;
    }
}

void update(int l,int r,int x)
{
    int lblock = (l/BLOCK);
    if((l%BLOCK) > 0) lblock++;
    
    int rblock = (r/BLOCK);
    if((r%BLOCK) < (BLOCK-1)) rblock--;
    
    bitset<BT> temp = x;
    
    if(l/BLOCK == r/BLOCK)
    {
        push(l/BLOCK);
        
        for(int i=l;i<=r;i++)
        f(j,BT) if(temp[j])
        { 
          data[i/BLOCK][j]-=a[i][j];
          a[i][j]=a[i][j]^1;
          data[i/BLOCK][j]+=a[i][j];    
        }
        
        return;
    }
    
    for(int i=lblock;i<=rblock;i++)
    {
       f(j,BT) if(temp[j]) 
       {
           data[i][j] = BLOCK - data[i][j];
           tag[i][j]^=1;
       }
    }
    
    push(l/BLOCK);
    
    for(int i=l;(i%BLOCK);i++)
    {
      f(j,BT) if(temp[j])
      { 
          data[i/BLOCK][j]-=a[i][j];
          a[i][j]=a[i][j]^1;
          data[i/BLOCK][j]+=a[i][j];
         
      }
    }
    
    push(r/BLOCK);
    
    for(int i=r;(i%BLOCK) < (BLOCK-1);i--)
    {
       f(j,BT) if(temp[j])
      { 
          data[i/BLOCK][j]-=a[i][j];
          a[i][j]=a[i][j]^1;
          data[i/BLOCK][j]+=a[i][j]; 
      } 
    }
}

long long query(int l,int r)
{
    int lblock = (l/BLOCK);
    if((l%BLOCK) > 0) lblock++;
    
    int rblock = (r/BLOCK);
    if((r%BLOCK) < (BLOCK-1)) rblock--;
    
    long long int res = 0;
    
    if(l/BLOCK == r/BLOCK)
    {
        push(l/BLOCK);
        
        for(int i=l;i<=r;i++)
            f(j,BT) res+=pw[j]*a[i][j];
        
        return res;
    }
    
    for(int i=lblock;i<=rblock;i++)
    {
       f(j,BT) res+=data[i][j]*pw[j];
    }
    
    push(l/BLOCK);
    
    for(int i=l;(i%BLOCK);i++)
    {
       f(j,BT) res+=a[i][j]*pw[j];
    }
    
    push(r/BLOCK);
    
    for(int i=r;(i%BLOCK) < (BLOCK-1);i--)
    {
        f(j,BT) res+=a[i][j]*pw[j];   
    }
    
    return res;
}

void solve()
{
   int n;
   cin >> n;
    
   int x;
    
   f(i,n)
   {
       cin >> x;
       a[i] = x;
   }
   
   build(n); 
    
   int q,t,l,r;
   cin >> q;
    
   while(q--)
   {
       cin >> t;
       
       if(t == 2)
       {
           cin >> l >> r >> x;
           update(l-1,r-1,x);
       }
       else
       {
           cin >> l >> r;
           cout << query(l-1,r-1) << '\n';
       }           
   }
}

signed main()
{
    f(i,BT) pw[i] = (1LL<<i);
    
    fast;
    solve();
}