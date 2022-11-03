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
std::vector<int>S;
int X[2010],Y[2010],ans[2010],siz[2010];
main(){
    int n,t=0;
    n=gi();
    for (int i=1;i<n;i++){
        X[i]=gi(),Y[i]=gi();
        if(X[i]>Y[i])std::swap(X[i],Y[i]);
        if(Y[i]!=n){puts("NO");return 0;}
    }
    std::sort(X+1,X+n);
    for(int i=1;i<n;i++)++siz[X[i]];
    for(int i=1;i<=n;i++)
        if(!siz[i])S.push_back(i),++t;
        else{
            if(siz[i]-1>t){puts("NO");return 0;}
            else{
                int cnt=siz[i]-1,x=i;
                t-=siz[i]-1;
                while(cnt--)ans[x]=S.back(),x=S.back(),S.pop_back();
                ans[x]=n;
            }
        }
    puts("YES");
    for(int i=1;i<n;i++)printf("%lld %lld\n",i,ans[i]);
    return 0;
}