#include<bits/stdc++.h>
#define il inline
#define vd void
il int gi(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f^=ch=='-',ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
struct string{
    std::string s;
    int w;
}s[510];
il bool operator<(const string&a,const string&b){return a.s<b.s;}
int head[510];
int Sw[510];
int LCP[510][510];
il vd chkmx(int&x,int y){if(y>x)x=y;}
std::vector<std::vector<int> >f[501][501];
std::map<std::string,int>M;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n=gi(),K=gi();
    std::string yybakioi;
    for(int i=1;i<=n;++i)std::cin>>yybakioi,M[yybakioi]+=gi();
    n=0;for(std::map<std::string,int>::iterator i=M.begin();i!=M.end();++i)s[++n]=(string){i->first,i->second};
    std::sort(s+1,s+n+1);
    for(int i=1;i<n;++i){
        head[i]=0;
        while(head[i]!=s[i].s.size()&&head[i]!=s[i+1].s.size()&&s[i].s[head[i]]==s[i+1].s[head[i]])++head[i];
    }
    for(int i=1;i<=n;++i){
        LCP[i][i]=s[i].s.size();
        for(int j=i+1;j<=n;++j)LCP[i][j]=std::min(LCP[i][j-1],head[j-1]);
    }
    for(int i=1;i<=n;++i)Sw[i]=Sw[i-1]+s[i].w;
    int ans=0,_max=0;
    for(int i=1;i<=n;++i)ans+=s[i].w*s[i].s.size();
    for(int l=1;l<=n;++l)
        for(int r=l;r<=n;++r)
            f[l][r].resize(LCP[l][r]+1);
    int now=0;
    for(int siz=1;siz<=n;++siz){
        for(int l=1;l+siz-1<=n;++l){
            int r=l+siz-1;
            for(int p=LCP[l][r];~p;--p){
                f[l][r][p].resize(K+1);
                for(int k=1;k<=K;++k){
                    now=0;
                    if(l!=r)now=std::max(f[l][r-1][p][k],f[l+1][r][p][k]);
                    if(LCP[l][r]>p)chkmx(now,f[l][r][LCP[l][r]][k-1]+(Sw[r]-Sw[l-1])*(LCP[l][r]-p));
                    for(int i=l;i<r;++i)
						for(int j=1;j<k;++j)
							chkmx(now,f[l][i][p][j]+f[i+1][r][p][k-j]);
                    f[l][r][p][k]=now;
                    _max=std::max(_max,now);
                }
            }
        }
    }
    printf("%d\n",ans-_max);
    return 0;
}