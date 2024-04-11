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
int a[101000],b[101000];
int ans[101000][2],ac;
int main(){
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int i,j;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<m;i++)scanf("%d",&b[i]);
    j=0;
    for(i=0;i<m;i++){
        while(j<n&&b[i]>a[j]+y)j++;
        if(j<n&&a[j]-x<=b[i]){
            ans[ac][0]=j+1;ans[ac][1]=i+1;
            ac++;j++;
        }
    }
    printf("%d\n",ac);
    for(i=0;i<ac;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
}