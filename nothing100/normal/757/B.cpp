#include<bits/stdc++.h>
#define MAXN 1000010
#define LL long long
using namespace std;
int n,ans[100010],anss;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        for (int j=1;j*j<=tmp;j++)
        if (tmp%j==0){
            ans[j]++;
            if (j*j!=tmp) ans[tmp/j]++;
        }
    }
    anss=1;
    for (int j=2;j<=100000;j++) anss=max(anss,ans[j]);
    printf("%d\n",anss);
}