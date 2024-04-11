#include<bits/stdc++.h>
using namespace std;
int n,ans,a[300010],f[15000010],pre[15000010],mgcd,maxa;
vector<int> pri;
void shai(){
    for (int i=2;i<=maxa;i++){
        if (f[i]==0) pri.push_back(i),pre[i]=i;
        for (int j=0;j<pri.size();j++){
            if (i*pri[j]>maxa) break;
            f[i*pri[j]]=1;
            pre[i*pri[j]]=pri[j];
            if (i%pri[j]==0) break;
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if (mgcd==0) mgcd=a[i];
        else mgcd=__gcd(mgcd,a[i]);
        maxa=max(maxa,a[i]);
    }
    shai();
    memset(f,0,sizeof(f));
    for (int i=0;i<n;i++){
        int last=-1,num=1;
        while (a[i]!=1){
            if (last!=pre[a[i]]){
                if (mgcd%num!=0) f[last]++;
                last=pre[a[i]];
                num=1;
            }
            num=num*last;
            a[i]/=last;
        }
        if (mgcd%num!=0) f[last]++;
        //printf("%d\n",f[last]);
    }
    ans=n;
    for (int i=1;i<=maxa;i++){
        ans=min(ans,n-f[i]);
    }
    if (ans==n) printf("-1\n");
    else printf("%d\n",ans);
}