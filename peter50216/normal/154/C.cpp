#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int in[1010000][2];
long long ha[1010000];
long long pow[1010000];
map<long long,int> XD;
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    long long ans=0;
    pow[0]=1;
    XD[1]=1;
    const int p=29;
    for(i=1;i<=n;i++){
        pow[i]=pow[i-1]*p;
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        in[i][0]=a;in[i][1]=b;
        ha[a]+=pow[b];
        ha[b]+=pow[a];
    }
    for(i=0;i<m;i++){
        int a=in[i][0],b=in[i][1];
        if(ha[a]+pow[a]==ha[b]+pow[b])ans++;
    }
    sort(ha,ha+n);
    for(i=0;i<n;i=j){
        for(j=i;j<n&&ha[i]==ha[j];j++);
        ans+=((long long)j-i)*((long long)j-i-1ll)/2;
    }
    printf("%I64d\n",ans);
}