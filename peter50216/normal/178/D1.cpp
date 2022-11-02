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
int num[20];
int t3[3]={4,3,0};
int d3[3][5][3]={
    {},
    {
        {5,4,3}
    },
    {
        {6,3,0},
        {8,4,0},
        {7,6,8},
        {1,4,7},
        {2,5,8}
    }
},dc3[3]={0,1,5};
int v3[3][2][3]={
    {},
    {},
    {
        {0,1,2},
        {2,4,6}
    }
},vc3[3]={0,0,2};
int t4[8]={5,6,9,10,4,8,0,1};
int d4[8][3][4]={
    {},
    {},
    {},
    {},
    {
        {7,4,5,6}
    },
    {
        {11,8,9,10}
    },
    {
        {12,0,4,8},
        {15,0,5,10},
        {3,7,11,15}
    },
    {
        {2,0,1,3},
        {13,1,5,9},
        {14,2,6,10}
    }
},dc4[8]={0,0,0,0,1,1,3,3};
int v4[8][2][4]={
    {},
    {},
    {},
    {},
    {},
    {},
    {
        {3,6,9,12}
    },
    {
        {12,13,14,15}
    }
},vc4[8]={0,0,0,0,0,0,1,1};
multiset<int> left;
inline bool add(int x){
    multiset<int>::iterator it=left.find(x);
    if(it==left.end())return 0;
    left.erase(it);
    return 1;
}
int ans[20];
int s;
bool flag=0;
inline void dfs3(int np){
    //printf("np=%d\n",np);
    int i,j,k;
    multiset<int>::iterator it;
    //for(i=0;i<9;i++)printf("%d%c",ans[i],(i%3==2?'\n':' '));
   // for(it=left.begin();it!=left.end();it++)printf(" %d",*it);
    //puts("");
    if(flag)return;
    if(np==3){
        printf("%d\n",s);
        for(i=0;i<9;i++)printf("%d%c",ans[i],(i%3==2?'\n':' '));
        flag=1;
        return;
    }
    int p=t3[np],pit=-1000000000;
    for(it=left.begin();it!=left.end();it++){
        if(*it==pit){
            continue;
        }
        pit=*it;
        ans[p]=pit;
        //printf("np=%d, put %d at %d\n",np,pit,p);
        left.erase(it);
        for(i=0;i<dc3[np];i++){
            ans[d3[np][i][0]]=s-ans[d3[np][i][1]]-ans[d3[np][i][2]];
            if(!add(ans[d3[np][i][0]]))break;
        }
        if(i==dc3[np]){
            for(i=0;i<vc3[np];i++){
                if(ans[v3[np][i][0]]+ans[v3[np][i][1]]+ans[v3[np][i][2]]!=s)break;
            }
            if(i==vc3[np]){
                dfs3(np+1);
                if(flag)return;
            }
            for(i=0;i<dc3[np];i++){
                left.insert(ans[d3[np][i][0]]);
      //          ans[d3[np][i][0]]=0;
            }
        }else{
      //          ans[d3[np][i][0]]=0;
            i--;
            for(;i>=0;i--){
                left.insert(ans[d3[np][i][0]]);
  //              ans[d3[np][i][0]]=0;
            }
        }
        it=left.insert(pit);
//        ans[p]=0;
    }
}
inline void dfs4(int np){
    //printf("np=%d\n",np);
    int i,j,k;
    multiset<int>::iterator it;
    //for(i=0;i<9;i++)printf("%d%c",ans[i],(i%3==2?'\n':' '));
   // for(it=left.begin();it!=left.end();it++)printf(" %d",*it);
    //puts("");
    if(flag)return;
    if(np==8){
        printf("%d\n",s);
        for(i=0;i<16;i++)printf("%d%c",ans[i],(i%4==3?'\n':' '));
        flag=1;
        return;
    }
    int p=t4[np],pit=-1000000000;
    for(it=left.begin();it!=left.end();it++){
        if(*it==pit){
            continue;
        }
        pit=*it;
        ans[p]=pit;
        //printf("np=%d, put %d at %d\n",np,pit,p);
        left.erase(it);
        for(i=0;i<dc4[np];i++){
            ans[d4[np][i][0]]=s-ans[d4[np][i][1]]-ans[d4[np][i][2]]-ans[d4[np][i][3]];
            if(!add(ans[d4[np][i][0]]))break;
        }
        if(i==dc4[np]){
            for(i=0;i<vc4[np];i++){
                if(ans[v4[np][i][0]]+ans[v4[np][i][1]]+ans[v4[np][i][2]]+ans[v4[np][i][3]]!=s)break;
            }
            if(i==vc4[np]){
                dfs4(np+1);
                if(flag)return;
            }
            for(i=0;i<dc4[np];i++){
                left.insert(ans[d4[np][i][0]]);
 //               ans[d4[np][i][0]]=0;
            }
        }else{
//                ans[d4[np][i][0]]=0;
            i--;
            for(;i>=0;i--){
                left.insert(ans[d4[np][i][0]]);
//                ans[d4[np][i][0]]=0;
            }
        }
        it=left.insert(pit);
//        ans[p]=0;
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    s=0;
    for(i=0;i<n*n;i++){
        scanf("%d",&num[i]);
        s+=num[i];
        left.insert(num[i]);
    }
    s/=n;
    if(n==1){
        printf("%d\n%d\n",s,s);
        return 0;
    }else if(n==2){
        printf("%d\n%d %d\n%d %d\n",s,s/2,s/2,s/2,s/2);
        return 0;
    }else if(n==3){
        dfs3(0);
    }else{
        dfs4(0);
    }
}