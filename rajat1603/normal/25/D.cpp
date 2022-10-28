#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define getchar_unlocked getchar
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
class dsu{
    int *parent;
    int *rank;
    public:
    void init(int n){
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i=1;i<=n;++i){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    bool join(int a,int b){
        int x = find(a);
        int y = find(b);
        if(x==y){
            return 0;
        }
        if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else if(rank[y]>rank[x]){
            parent[x]=y;
        }
        else{
            parent[y]=x;
            ++rank[x];
        }
        return 1;
    }
};
queue<int> close1;
queue<int> close2;
queue<int> join1;
dsu mydsu;
int main(){
    int n=scan();
    mydsu.init(n);
    int ans=0;
    for(int i=1;i<n;++i){
        int a=scan(),b=scan();
        if(!mydsu.join(a,b)){
            close1.push(a);
            close2.push(b);
            ans++;
        }
    }
    for(int i=2;i<=n;++i){
        if(mydsu.join(1,i)){
            join1.push(i);
        }
    }
    printf("%d\n",ans);
    while(!close1.empty()){
        printf("%d %d %d %d\n",close1.front(),close2.front(),1,join1.front());
        close1.pop();
        close2.pop();
        join1.pop();
    }
}