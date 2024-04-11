#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p[310],ans[310],where[310],what[310];
char a[310][310];
bool f[310][310],visited[310];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    getchar();
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            f[i][j] = a[i][j]-'0';
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                f[i][j] = f[i][j] || (f[i][k] && f[k][j]);
    for (int i=0; i<n; i++){
        memset(where,0,sizeof(where));
        memset(what,0,sizeof(what));
        int loc=0;
        for (int j=0; j<n; j++){
            if(f[i][j]==1){
                if(!visited[j]){
                    where[loc]=j;
                    what[loc++]=p[j];
                    visited[j]=1;
                }
            }
            sort(what,what+loc);
            for(int k=0;k<loc;k++){
                ans[where[k]]=what[k];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i])ans[i]=p[i];
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}