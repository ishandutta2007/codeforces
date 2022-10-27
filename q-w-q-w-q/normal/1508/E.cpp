#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int N=300005;
int n,a[N],mp[N],x,y,t,z;
int fa[N],s[N],dep[N],cnt,tot,s1;
int dfn[N];
long long ans;
vector<int> to[N];
inline bool cmp(int i,int j){return dfn[i]<dfn[j];}
inline void dfs(int i){
    for(int j:to[i])
        if(j!=fa[i])
            s[i]++,dep[j]=dep[i]+1,fa[j]=i,dfs(j);
}
inline bool check(int i){
    tot++;
    if(dfn[i]!=tot) return 0;
    if(a[i]>t){
        s1++;
        if(a[i]!=s1+t) return 0;
    }
    sort(to[i].begin(),to[i].end(),cmp);
    for(int j:to[i])
        if(j!=fa[i]&&!check(j)) return 0;
    return 1;
}
inline void print(){
    if(check(1)){
        puts("YES");
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) printf("%d%c",dfn[i]," \n"[i==n]);
    }
    else puts("NO");
    exit(0);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",dfn+i),mp[dfn[i]]=i,a[i]=dfn[i];
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        to[x].push_back(y),to[y].push_back(x);
    }
    dfs(1);
    for(int i=mp[1];i;i=fa[i]) cnt++;
    for(int i=mp[1],j=0;i;i=fa[i],j++) dfn[i]=dep[i]+1;
    for(t=1;t<n;t++){
        x=mp[t],ans+=dep[x];
        if(s[x]) print();
        y=mp[t+1],x=fa[x],s[x]--;
        z=y;
        for(int i=0;i<dep[y]-dep[x];i++) z=fa[z];
        if(z!=x) t++,ans+=dep[z],print();
        cnt+=dep[y]-dep[x];
        for(int j=0,z=y;z!=x;z=fa[z],j++) dfn[z]=cnt-j;
  }
  print();
}