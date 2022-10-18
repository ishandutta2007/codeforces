#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#define forn(i,n) for (int (i)=0;(i)<(n);i++)
#define pb push_back

using namespace std;
vector <int> d;
bool on[100500];
int p[100500];

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n,m;
    memset(on,false,sizeof(on));
    memset(p,0,sizeof(p));
    cin >> n >> m;
    scanf("\n");
    forn(i,m)
    {
     char c = getchar();
     int d; scanf("%d\n",&d);
     if (c == '+')
     {
           
           if  (on[d]) { printf("Already on\n"); continue; }
           int dd = d; 
           vector <int> pr;
           for (int j=2; j*j <= dd; j++)
           {
               if  (j > d) break;
               if  (d % j != 0) continue;
               while (d % j == 0) d/=j;
               pr.pb(j);
           }
           if  (d > 1) pr.pb(d); bool ok = 1;
           forn(i,(int)pr.size()) 
            if  (p[pr[i]] != 0 && on[p[pr[i]]]) 
            { printf("Conflict with %d\n",p[pr[i]]); ok = 0; break; }
           if  (!ok) continue;
           printf("Success\n");
           on[dd] = true; 
           forn(j,(int)pr.size()) p[pr[j]] = dd; 
           
     } else
           if  (on[d]) { printf("Success\n"); on[d] = false; } else printf("Already off\n");
    }
    return 0;
}