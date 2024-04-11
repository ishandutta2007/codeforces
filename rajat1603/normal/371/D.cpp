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
const int N = 200001;
int parent[N];
int arr[N];
int cur[N]={0};
int n,q;
int find(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=find(parent[node]);
}
int main(){
    n=scan();
    for(int i=1;i<=n;++i){
        parent[i]=i;
        arr[i]=scan();
    }
    parent[n+1]=n+1;
    q=scan();
    while(q--){
        int type=scan();
        if(type==1){
            int pos=scan(),val=scan();
            int prev=-1;
            while(val>0&&pos<=n){
                pos=find(pos);
                if(prev!=-1)
                parent[prev]=pos;
                cur[pos]+=val;
                val = cur[pos]-arr[pos];
                cur[pos]=min(cur[pos],arr[pos]);
                prev = pos;
                pos++;
            }
        } 
        else{
            int pos=scan();
            printf("%d\n",min(cur[pos],arr[pos]));
        }
    }
}