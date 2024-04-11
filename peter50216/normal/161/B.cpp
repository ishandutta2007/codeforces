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
int n,k;
int c[1010],t[1010];
vector<pair<int,int> > a0,a1;
vector<int> out[1010];
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    long long s=0;
    for(i=0;i<n;i++){
        scanf("%d%d",&c[i],&t[i]);
        s+=c[i]*2;
        if(t[i]==1)a0.push_back(make_pair(c[i],i));
        else a1.push_back(make_pair(c[i],i));
    }
    sort(a0.begin(),a0.end());
    sort(a1.begin(),a1.end());
    int a0c=a0.size(),a1c=a1.size();
    if(a0c<k){
        for(i=0;i<a0c;i++){
            out[i].push_back(a0[i].second);
            s-=a0[i].first;
        }
        int r=k-a0.size();
        for(i=0;i<r;i++)out[a0c+i].push_back(a1[i].second);
        for(i=r;i<a1c;i++)out[a0c].push_back(a1[i].second);
    }else{
        for(i=a0c-1;i>=a0c-k;i--){
            out[i-(a0c-k)].push_back(a0[i].second);
            if(i>a0c-k)s-=a0[i].first;
        }
        for(i=a0c-k-1;i>=0;i--)out[0].push_back(a0[i].second);
        for(i=0;i<a1c;i++)out[0].push_back(a1[i].second);
        if(a1c==0||a1[0].first>=a0[0].first)s-=a0[0].first;
        else s-=a1[0].first;
    }
    printf("%I64d.%d\n",s/2,(s%2==0?0:5));
    for(i=0;i<k;i++){
        printf("%d",out[i].size());
        for(j=0;j<out[i].size();j++)printf(" %d",out[i][j]+1);
        puts("");
    }
}