#include <bits/stdc++.h>
using namespace std;

#define S second
#define F first
#define f(i,n) for(int i=1;i<=n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>

const int N = 3e5+10;

pii dsu[2*N];
string s;
int g[N][2],n,k,x,c,ans = 0,flag[2*N];

int find(int x)
{
    if(dsu[x].F == x) return x;
    return dsu[x].F = find(dsu[x].F);
}

void merge(int x,int y)
{
    int a = find(x);  int b = find(y);
    
    if(a==b) return;
    
    dsu[b].S+=dsu[a].S;
    dsu[a].F = dsu[b].F;
    flag[b]|=flag[a];
}

int calc(int x)
{
    int a = find(x);  int b = find(x+k);
    if(flag[a]) return dsu[a].S;
    if(flag[b]) return dsu[b].S;
    return min(dsu[a].S,dsu[b].S);
}

signed main()
{
    fast;

    cin >> n >> k >> s;
 
   f(i,k)
   {
       cin >> c;
       
       while(c--)
       {
           cin >> x;
           if(g[x][0] == 0) g[x][0] = i;
           else g[x][1] = i;
       }
   }
    
   f(i,k+k) dsu[i] = {i,i<=k};
   
    f(i,n)
    {
        if(g[i][0] > 0 && g[i][1] > 0)
        {
            if(s[i-1] == '1' && find(g[i][0]) != find(g[i][1]))
             {
                  ans-=calc(g[i][0]) + calc(g[i][1]);
                  merge(g[i][0],g[i][1]);
                  merge(g[i][0] + k,g[i][1] + k);   
                  ans+=calc(g[i][0]);  
             }
            else if(s[i-1] == '0' && find(g[i][0]) != find(g[i][1] + k))
             {
                  ans-=calc(g[i][0]) + calc(g[i][1]);
                  merge(g[i][0] + k,g[i][1]);  
                  merge(g[i][0],g[i][1] + k);  
                  ans+=calc(g[i][0]);  
             }
        }
        else if(g[i][0] > 0)
        {
                ans-=calc(g[i][0]);
                if(s[i-1] == '1') flag[find(g[i][0]+k)] = 1;
                else flag[find(g[i][0])] = 1;
                ans+=calc(g[i][0]);  
        }
                 
        cout << ans << '\n';
    }
}