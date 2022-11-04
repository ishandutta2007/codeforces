#include <cstdio>
#include <algorithm>
struct Data{
   int poz;
   int val;
};
Data v[200];
bool cmp(Data a,Data b){
   return a.val<b.val;
}
int main(){
    int i,n,b,e;
    scanf("%d" ,&n);
    for(i=1;i<=n;i++){
      scanf("%d" ,&v[i].val);
      v[i].poz=i;
    }
    std::sort(v+1,v+n+1,cmp);
    b=1;
    e=n;
    while(b<e){
        printf("%d %d\n" ,v[b].poz,v[e].poz);
        b++;
        e--;
    }
    return 0;
}