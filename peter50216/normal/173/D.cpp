#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ed[101000];
int n;
int col[101000];
inline void dfs(int np,int c){
    if(col[np])return;
    col[np]=c;
    for(int i=0;i<ed[np].size();i++)dfs(ed[np][i],3-c);
}
int u[101000];
int to[101000];
int cnt[101000];
vector<int> ccc;
int main(){
    int m;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    int i,j;
    for(i=0;i<n;i++)if(col[i]==0)dfs(i,1);
    int c1=0;
    for(i=0;i<n;i++)if(col[i]==1)c1++;
    int c2=n-c1;
    if(c1%3==0){
        puts("YES");
        int cc1=3,cc1t=0,cc2=3,cc2t=0,tt=1;
        for(i=0;i<n;i++){
            if(col[i]==1){
                if(cc1==3){
                    cc1=0;
                    cc1t=tt++;
                }
                printf("%d",cc1t);
                cc1++;
            }else{
                if(cc2==3){
                    cc2=0;
                    cc2t=tt++;
                }
                printf("%d",cc2t);
                cc2++;
            }
            printf("%c",i==n-1?'\n':' ');
        }
        return 0;
    }else{
        if(c1%3==2){
            for(i=0;i<n;i++)col[i]=3-col[i];
            swap(c1,c2);
        }
        //printf("c1=%d c2=%d\n",c1,c2);
        //for(i=0;i<n;i++)printf("%d ",col[i]);
        //puts("");
        for(i=0;i<n;i++)if(col[i]==1&&ed[i].size()<=c2-2)break;
        if(i<n){
            int a1=i,a2=-1,a3=-1;
            for(i=0;i<ed[a1].size();i++)u[ed[a1][i]]=1;
            for(i=0;i<n&&a3==-1;i++){
                if(col[i]==2&&u[i]==0){
                    if(a2==-1)a2=i;
                    else a3=i;
                }
            }
            puts("YES");
            int cc1=3,cc1t=0,cc2=3,cc2t=0,tt=1;
            for(i=0;i<n;i++){
                if(i==a1||i==a2||i==a3){
                    printf("%d",n/3);
                }else{
                    if(col[i]==1){
                        if(cc1==3){
                            cc1=0;
                            cc1t=tt++;
                        }
                        printf("%d",cc1t);
                        cc1++;
                    }else{
                        if(cc2==3){
                            cc2=0;
                            cc2t=tt++;
                        }
                        printf("%d",cc2t);
                        cc2++;
                    }
                }
                printf("%c",i==n-1?'\n':' ');
            }
            return 0;
        }
        int uid=1;
        for(i=0;i<n;i++)if(col[i]==2)ccc.push_back(i);
        for(i=0;i<n;i++){
            if(col[i]==2)continue;
            if(ed[i].size()==c2){
                to[i]=-1;
                continue;
            }
            uid++;
            for(j=0;j<ed[i].size();j++){
                u[ed[i][j]]=uid;
            }
            for(j=0;j<ccc.size();j++)if(u[ccc[j]]!=uid){
                to[i]=ccc[j];
                //printf("to[%d]=%d\n",i,ccc[j]);
                break;
            }
        }
        for(i=0;i<n;i++)if(col[i]==1&&to[i]!=-1)cnt[to[i]]++;
        int a1=-1,a2=-1;
        int b1=-1,b2=-1,b3=-1,b4=-1;
        for(i=0;i<n&&a2==-1;i++){
            if(cnt[i]>=2){
                if(a1==-1)a1=i;
                else a2=i;
            }
        }
        if(a2!=-1){
            for(i=0;i<n&&(b2==-1||b4==-1);i++){
                if(col[i]==2)continue;
                if(to[i]==a1){
                    if(b1==-1)b1=i;
                    else b2=i;
                }else if(to[i]==a2){
                    if(b3==-1)b3=i;
                    else b4=i;
                }
            }
            //printf("%d %d %d %d\n",b1,b2,b3,b4);
            puts("YES");
            int cc1=3,cc1t=0,cc2=3,cc2t=0,tt=1;
            for(i=0;i<n;i++){
                if(i==a1||i==b1||i==b2){
                    printf("%d",n/3);
                }else if(i==a2||i==b3||i==b4){
                    printf("%d",n/3-1);
                }else{
                    if(col[i]==1){
                        if(cc1==3){
                            cc1=0;
                            cc1t=tt++;
                        }
                        printf("%d",cc1t);
                        cc1++;
                    }else{
                        if(cc2==3){
                            cc2=0;
                            cc2t=tt++;
                        }
                        printf("%d",cc2t);
                        cc2++;
                    }
                }
                printf("%c",i==n-1?'\n':' ');
            }
            return 0;
        }
        puts("NO");
    }
}