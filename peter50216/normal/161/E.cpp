#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char in[10];
bool np[101000];
int pr[101000],pc;
vector<int> pre[6][6][101000];
inline void init(){
    long long i,j;
    for(i=2;i<100000;i++)if(!np[i]){
        pr[pc++]=i;
        for(j=i*i;j<=100000;j+=i)np[j]=1;
    }
}
inline void init2(){
    int i,j;
    for(i=0;i<pc;i++){
        int k=0;
        char tmp[10];
        sprintf(tmp,"%d",pr[i]);
        int r=strlen(tmp);
        for(j=0,k=r-1;j<k;j++,k--){
            swap(tmp[j],tmp[k]);
        }
        while(r<=5){
            k=0;
            for(j=r-1;j>=0;j--){
                pre[j+1][r-1-j][k].push_back(pr[i]);
                k=k*10+tmp[j]-'0';
            }
            tmp[r++]='0';
        }
    }
}
int n;
int num[6];
int ans=0;
inline void dfs(int np){
    if(np==n){
       // for(int i=0;i<n;i++)printf("%02d\n",num[i]);
        //puts("");
        ans++;
        return;
    }
    int i,j;
    //printf("np=%d n-np=%d num=%d\n",np,n-np,num[np]);
    for(i=0;i<pre[n-np][np][num[np]].size();i++){
        int y=pre[n-np][np][num[np]][i];
        //printf("%d\n",y);
      //  int kk=num[np];num[np]=y;
        for(j=n-1;j>=np+1;j--){
            num[j]=num[j]*10+y%10;
            y/=10;
        }
        dfs(np+1);
       // num[np]=kk;
        for(j=np+1;j<n;j++){
            num[j]/=10;
        }
    }
}
int main(){
    init();init2();
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%s",in);
        n=strlen(in);
        sscanf(in,"%d",&num[0]);
        for(i=1;i<n;i++)num[i]=in[i]-'0';
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
}