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
char S[1010][1010],S2[1010][1010];
int X[]={0,1,1,1,0,0,-1,-1,-1},Y[]={0,-1,0,1,1,-1,1,0,-1};
main(){
    int n=gi(),m=gi();
    for(int i=1;i<=n;++i)scanf("%s",S[i]+1);
    for(int i=2;i<n;++i)
        for(int j=2;j<m;++j){
            int flg=1;
            for(int k=1;k<9;++k)if(S[i+X[k]][j+Y[k]]=='.')flg=0;
            if(flg)for(int k=1;k<9;++k)S2[i+X[k]][j+Y[k]]=1;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(S[i][j]=='#'&&!S2[i][j])return puts("NO"),0;
    puts("YES");
    return 0;
}