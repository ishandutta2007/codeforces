#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug
#define ll long long
#define move ouehfri
#define left cjsbsoiyafg

struct seg {
    int x,y,id;
    bool operator<(seg cmp)const{
        if(x == cmp.x)
            return y > cmp.y;
        return x < cmp.x;
    }
    
}

v[maxn];

main(){
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
       scanf("%d%d",&v[i].x,&v[i].y);
       v[i].id = i+1;
   }
   sort(v,v+n);
   int bx = -1, id;
   for(int i=0;i<n;i++){
       if(bx >= v[i].y){
           printf("%d %d\n",v[i].id,id);
           return 0;
       }
       if(v[i].y > bx){
           bx = v[i].y;
           id = v[i].id;
       }
   }
    
    printf("-1 -1\n");
}