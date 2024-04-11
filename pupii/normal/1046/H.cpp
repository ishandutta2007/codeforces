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
char s[1000010];
std::map<int,int>M;
main(){
    int n=gi(),ans=0;
    for(int i=1;i<=n;++i){
        scanf("%s",s+1);
        int l=strlen(s+1),ha=0;
        for(int j=1;j<=l;++j)ha^=1<<(s[j]-'a');
        for(int j=0;j<26;++j)ha^=1<<j,ans+=M[ha],ha^=1<<j;
        ans+=M[ha];
        ++M[ha];
    }
    printf("%lld\n",ans);
    return 0;
}