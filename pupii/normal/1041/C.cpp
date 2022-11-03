#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
std::map<int,int>ans;
int a[200010],b[200010],Ans;
std::priority_queue<int>que;
main(){
    int n=gi(),m=gi(),d=gi();
    for(int i=1;i<=n;++i)a[i]=b[i]=gi();
    std::sort(b+1,b+n+1);
    for(int x=1;x<=n;++x){
        int i=b[x];
        if(!que.empty()&&-que.top()+d<i)ans[i]=ans[-que.top()],que.pop(),que.push(-i);
        else ans[i]=++Ans,que.push(-i);
    }
    printf("%lld\n",Ans);
    for(int i=1;i<=n;++i)printf("%lld ",ans[a[i]]);
    return 0;
}