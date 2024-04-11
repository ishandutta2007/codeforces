#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<cmath>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
#define int long long
const int N=5e5+55;
inline int read(){
  char c=getchar();int s=0;
  while(c<'0' || c>'9')c=getchar();
  while(c>='0' && c<='9'){
    s=s*10+c-'0';c=getchar();
  }
  return s;
}
int n,x,y,ans,f[N][2],a[N],b[N];
vi v[N];
int st[N],top;
void add(int x,int y){
   v[x].pb(y);v[y].pb(x);
}
int cmp(int x,int y){
  return x>y;
}
void dfs(int u,int fa){
   f[u][0]=f[u][1]=1e15;
   int siz=0;   
   int xx=0,yy=0,zz=0;
   for(int i=0;i<v[u].size();i++){
      if(v[u][i]==fa)continue;
      siz++;
      dfs(v[u][i],u);
      if(b[u]!=b[v[u][i]]){
        if(b[u]<b[v[u][i]]){
          zz+=f[v[u][i]][1];
          xx++;
        }
        else{
          zz+=f[v[u][i]][0];
          yy++;
        }
      }
   }
   if(!siz){
	    f[u][0]=f[u][1]=a[u];
	    return ;
   }
   top=0;
    for(int i=0;i<v[u].size();i++){
    	if(v[u][i]==fa)continue;
   	 	if(b[u]==b[v[u][i]]){
   	 		
   		   	zz+=f[v[u][i]][1];
   	  		st[++top]=f[v[u][i]][0]-f[v[u][i]][1];
   	   	    xx++;
		/*	if(u==1){
   	 			cout<<"???:"<<v[u][i]<<" "<<st[top]<<endl;
			}*/
        }
    }
	
  /*  if(u==1){
    	cout<<"sese:"<<st[1]<<endl;
	}*/
    if(u==1){
	  	sort(st+1,st+top+1);
	    ans=zz+max(xx,yy)*a[u];
	    for(int i=1;i<=top;i++){  
	      
	      xx--;yy++;zz+=st[i];
	      ans=min(ans,zz+max(xx,yy)*a[u]);
	    }
	    return ;
    }
    sort(st+1,st+top+1,cmp);
    f[u][0]=zz+max(xx+1,yy)*a[u];
    f[u][1]=zz+max(xx,yy+1)*a[u];
    while(top){
   	  zz+=st[top];
   	  xx--;yy++;
   	  top--;
   	  f[u][0]=min(f[u][0],zz+max(xx+1,yy)*a[u]);
   	  f[u][1]=min(f[u][1],zz+max(xx,yy+1)*a[u]);
   }
}
signed main(){
//	freopen("data.in","r",stdin);
   n=read();
   for(int i=1;i<=n;i++){
       a[i]=read();
   }
   for(int i=1;i<=n;i++){
       b[i]=read();
   }
   for(int i=1;i<n;i++){
       x=read();y=read();
       add(x,y);
   }
   dfs(1,0);
  // cout<<f[3][0]<<" "<<f[3][1]<<endl;
   //cout<<f[2][1]<<endl;
   cout<<ans;
   return 0;
}