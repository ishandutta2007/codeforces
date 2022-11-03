#include<bits/stdc++.h>
#define il inline
#define vd void
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,k;
ll f[37][71];
std::vector<int>a[71],b[71];
int main(){
    n=gi(),k=gi();
    char opt[3];int x,y,p;
    for(int i=1;i<=k;++i){
        scanf("%d%s%d",&x,opt,&y);
        if(opt[0]=='=')p=0;
        else if(opt[0]=='<'&&opt[1]=='\0')p=1;
        else if(opt[0]=='<'&&opt[1]=='=' )p=2;
        else if(opt[0]=='>'&&opt[1]=='\0')p=-1;
        else if(opt[0]=='>'&&opt[1]=='=' )p=-2;
        else puts("wrong answer!");
        a[x].push_back(y),b[x].push_back(p);
        a[y].push_back(x),b[y].push_back(-p);
    }
    f[1][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=(i-1)*2;++j){
            int l=j+1,r=j+(n-i+1)*2;
            for(int s=0;s<a[l].size();++s){
                int A=a[l][s],B=b[l][s];
                if((A<l||A>r)&&B>=0)goto GG1;
                if((A>l+1&&A<=r)&&B<=0)goto GG1;
                if((A==l||A==l+1)&&(B==1||B==-1))goto GG1;
            }
            for(int s=0;s<a[l+1].size();++s){
                int A=a[l+1][s],B=b[l+1][s];
                if((A<l||A>r)&&B>=0)goto GG1;
                if((A>l+1&&A<=r)&&B<=0)goto GG1;
                if((A==l||A==l+1)&&(B==1||B==-1))goto GG1;
            }
            f[i+1][j+2]+=f[i][j];
            GG1:;
            for(int s=0;s<a[r].size();++s){
                int A=a[r][s],B=b[r][s];
                if((A<l||A>r)&&B>=0)goto GG2;
                if((A>=l&&A<r-1)&&B<=0)goto GG2;
                if((A==r||A==r-1)&&(B==1||B==-1))goto GG2;
            }
            for(int s=0;s<a[r-1].size();++s){
                int A=a[r-1][s],B=b[r-1][s];
                if((A<l||A>r)&&B>=0)goto GG2;
                if((A>=l&&A<r-1)&&B<=0)goto GG2;
                if((A==r||A==r-1)&&(B==1||B==-1))goto GG2;
            }
            f[i+1][j]+=f[i][j];
            GG2:;
            for(int s=0;s<a[l].size();++s){
                int A=a[l][s],B=b[l][s];
                if((A<l||A>r)&&B>=0)goto GG3;
                if((A>l&&A<r)&&B<=0)goto GG3;
                if((A==l||A==r)&&(B==1||B==-1))goto GG3;
            }
            for(int s=0;s<a[r].size();++s){
                int A=a[r][s],B=b[r][s];
                if((A<l||A>r)&&B>=0)goto GG3;
                if((A>l&&A<r)&&B<=0)goto GG3;
                if((A==l||A==r)&&(B==1||B==-1))goto GG3;
            }
            f[i+1][j+1]+=f[i][j];
            GG3:;
        }
    ll ans=0;for(int i=0;i<=n*2;++i)ans+=f[n+1][i];
    printf("%lld\n",ans/3);
    return 0;
}