#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int m[1<<7][1<<7],has[1<<14],in[1<<14],out[1<<14];
vector<int>e[1<<14],ans;
void euler(int u)
{
    while(out[u]>0){
        out[u]--;
        euler(e[u][out[u]]);
    }
    ans.push_back(u);
}
int main()
{
    int n,a[5],cnt=0;
    char s[5];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<3;j++){
            a[j]=(int)s[j];
        }
        if(!m[a[0]][a[1]]){
            m[a[0]][a[1]]=++cnt;
            has[cnt]=a[0]*(1<<7)+a[1];
        }
        if(!m[a[1]][a[2]]){
            m[a[1]][a[2]]=++cnt;
            has[cnt]=a[1]*(1<<7)+a[2];
        }
        e[m[a[0]][a[1]]].push_back(m[a[1]][a[2]]);
        out[m[a[0]][a[1]]]++;
        in[m[a[1]][a[2]]]++;
    }
    bool isok=1;
    int cnts=0,cntf=0,st=1;
    for(int i=1;i<=cnt;i++){
        if(out[i]==in[i])continue;
        else if(out[i]-in[i]==1){
            cnts++;
            st=i;
        }
        else if(out[i]-in[i]==-1)cntf++;
        else{
            isok=0;
            break;
        }
    }
    if(cnts>1||cntf>1)isok=0;
    if(!isok)printf("NO");
    else{
        euler(st);
        if(ans.size()<n+1)printf("NO");
        else{
            printf("YES\n");
            for(int i=n;i>=0;i--){
                printf("%c",has[ans[i]]/(1<<7));
            }
            printf("%c",has[ans[0]]%(1<<7));
        }
    }
    return 0;
}