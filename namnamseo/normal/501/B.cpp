#include <cstdio>
typedef unsigned long long ull;
char data[2][1010][21];
int len[2][1010];
int next[1010];
bool visited[1010];
ull hash[2][1010][2];
int prime[2]={65537,1000000007};
int n;
bool starter[1010];
int ending[1010];

int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;++i) scanf("%s%s",data[0][i],data[1][i]);
    for(i=0;i<n;++i){
        for(j=0;data[0][i][j];++j); len[0][i]=j;
        for(j=0;data[1][i][j];++j); len[1][i]=j;
        for(j=0;j<len[0][i];++j) {
            hash[0][i][0]=hash[0][i][0]*prime[0]+data[0][i][j];
            hash[0][i][1]=hash[0][i][1]*prime[1]+data[0][i][j];
        }
        for(j=0;j<len[1][i];++j) {
            hash[1][i][0]=hash[1][i][0]*prime[0]+data[1][i][j];
            hash[1][i][1]=hash[1][i][1]*prime[1]+data[1][i][j];
        }
        for(j=0;j<i;++j){
            if(len[1][j]==len[0][i] && 
               hash[1][j][0]==hash[0][i][0] && hash[1][j][1]==hash[0][i][1]){
                   next[j]=i;
                   break;
               }
        }
    }
    int cnt=0;
    for(i=0;i<n;++i){
        if(visited[i]) continue;
        for(j=i;next[j];j=next[j]){
            visited[j]=true;
        }
        visited[j]=true;
        ++cnt;
        starter[i]=true;
        ending[i]=j;
    }
    printf("%d\n",cnt);
    for(i=0;i<n;++i){
        if(starter[i]) printf("%s %s\n",data[0][i],data[1][ending[i]]);
    }
    return 0;
}