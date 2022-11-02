#include<bits/stdc++.h>
using namespace std;
int n,s,num[100010];
int main(){
    scanf("%d%d",&n,&s);
    for (int i=1;i<n;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        num[o]++;
        num[p]++;
    }
    int leaf=0;
    for (int i=1;i<=n;i++)
    if (num[i]==1) leaf++;
    printf("%.9f\n",2.0*s/leaf);
}