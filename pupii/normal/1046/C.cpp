#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int S[300010];
int P[300010];
std::multiset<int>yyb;
main(){
    int n=gi(),p=gi();
    for(int i=1;i<=n;++i)S[i]=gi();
    S[p]-=1000000000;
    std::sort(S+1,S+n+1);
    S[1]+=1000000000;
    for(int i=1;i<=n;++i)P[i]=gi(),yyb.insert(P[i]);
    S[1]+=*--yyb.end();yyb.erase(--yyb.end());
    int ans=1;
    for(int i=n;i>1;--i)
        if(*yyb.begin()+S[i]<=S[1]){
            std::set<int>::iterator it=yyb.upper_bound(S[1]-S[i]);
            if(it==yyb.begin())yyb.erase(it);
            else yyb.erase(--it);
        }
        else ++ans,yyb.erase(--yyb.end());
    printf("%lld\n",ans);
    return 0;
}