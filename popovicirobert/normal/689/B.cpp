#include <cstdio>
#include <vector>
using namespace std;
vector <int> G[200001];
int cod[200001],viz[200001];
inline void BFS(int nod){
    int b,e,i;
    cod[0]=nod;
    viz[nod]=1;
    b=0;
    e=1;
    do{
        nod=cod[b];
        for(i=0;i<G[nod].size();i++)
          if(viz[G[nod][i]]==0){
             viz[G[nod][i]]=viz[nod]+1;
             cod[e++]=G[nod][i];
          }
        b++;
    }while(b<e);
}
int main(){
    int n,i,x;
    scanf("%d" ,&n);
    for(i=1;i<=n;i++){
        scanf("%d" ,&x);
        G[i].push_back(x);
        if(i<n){
          G[i].push_back(i+1);
          G[i+1].push_back(i);
        }
    }
    BFS(1);
    for(i=1;i<=n;i++)
      printf("%d " ,viz[i]-1);
    return 0;
}