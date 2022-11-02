#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pip pair<ll,pii>
#define debug 
#define ll long long
#define move ouehfri
#define left cjsbsoiyafg

vector<pii> edge;

int dg[330];
int aux[330];

void build(int a,int b,int t){
    
    debug("bd %d~%d ",a,b);
    for(int i=0;i<t;i++)debug("%d ",dg[i]);
    debug("\n");

    int x = dg[0], y = dg[1], z = dg[t-1];
 
    int tt = y-z+1;
 
    pii A (a,a+z-1);
    pii B (a+z,b-tt);
    pii C (b-tt+1,b);
    

    for(int i=A.first;i<=A.second;i++)
        for(int j=i+1;j<=b;j++)
            edge.pb(pii(i,j));
    debug("+edge %d-%d ~ %d-%d\n",A.first,A.second,A.first,b);
            
    if(t <= 2)
        return;
            
    int u = 0;
    for(int i=1;i<t-1;i++)
        aux[u++] = dg[i]-z;

    for(int i=0;i<u;i++)
        dg[i] = aux[i];

    build(C.first,C.second,u);

}

main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        dg[n-i-1] = a;
    }
   

    build(0,dg[0],n);
    
    printf("%d\n",edge.size());
    for(int i=0;i<edge.size();i++)
        printf("%d %d\n",1+edge[i].first,1+edge[i].second);
        
}