#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
il int gi(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
std::map<int,int>yyb;
const int maxn=200001;
int w[maxn],p[maxn],l[maxn],r[maxn];
std::vector<int>S[maxn];
int ans[maxn],Ans=-1,t[1000100],tt[1000100],lst[maxn],f[maxn];
main(){
    int n=gi();
    for(int i=1;i<=n;++i){
        w[i]=gi(),p[i]=gi(),l[i]=gi(),r[i]=gi();
        int s=p[i]+l[i]+r[i];
        if(yyb[s]==0)yyb[s]=i;
        S[yyb[s]].push_back(i);
    }
    for(int i=1;i<=n;++i){
        if(!S[i].size())continue;
        tt[0]=i,t[0]=-1;
        int mx=-1;
        for(int j=0;j<S[i].size();++j){
            if(tt[l[S[i][j]]]!=i)continue;
            lst[j]=t[l[S[i][j]]];
            f[j]=f[lst[j]]+w[S[i][j]];
            int np=l[S[i][j]]+p[S[i][j]];
            if(np<1000001&&(tt[np]!=i||f[t[np]]<f[j]))tt[np]=i,t[np]=j;
            if(r[S[i][j]]==0&&f[mx]<f[j])mx=j;
        }
        if(~mx&&Ans<f[mx]){
            Ans=f[mx];
            ans[0]=0;
            for(int j=mx;~j;j=lst[j])ans[++ans[0]]=S[i][j];
        }
    }
    if(Ans==-1)puts("0");
    else{
        printf("%lld\n",ans[0]);
    	for(int i=ans[0];i;--i)printf("%lld ",ans[i]);
    	puts("");
    }
    return 0;
}