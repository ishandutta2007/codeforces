#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 200001;
int arr[N];
list<int> v[N];
int bit[N]={0};
bool depth[N]={0};
int start[N]={0};
int finish[N]={0};
int timer=0;
int n,m;
void dfs(int node =1,int parent= -1){
	start[node]=++timer;
	for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
		if(*it!=parent){
			depth[*it]=depth[node]^1;
			dfs(*it,node);
		}
	}
	finish[node]=timer;
}
inline int query(int idx){
	int res=0;
	while(idx){
        res+=bit[idx];
        idx&=idx-1;
	}
	return res;
}
inline void update(int idx,int val){
    while(idx<=timer){
    	bit[idx]+=val;
    	idx+=idx&-idx;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
    	scanf("%d",arr+i);
    } 
    for(int i=1;i<n;++i){
    	int a,b;
        scanf("%d %d",&a,&b);
    	v[a].pb(b);
    	v[b].pb(a);
    }
    dfs();
    while(m--){
    	int type;
    	scanf("%d",&type);
    	if(type==1){
    		int node,val;
            scanf("%d %d",&node,&val);
            if(depth[node]){
            	update(finish[node]+1,val);
            	update(start[node],-val);
            }
            else{
            	update(start[node],val);
            	update(finish[node]+1,-val);
            }
    	}
    	else{
    		int node;
    		scanf("%d",&node);
    		if(depth[node]){
    			printf("%d\n",arr[node]-query(start[node]));
    		}
    		else{
    			printf("%d\n",arr[node]+query(start[node]));
    		}
    	}
    }
}