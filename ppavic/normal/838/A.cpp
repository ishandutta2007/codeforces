#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2505;

int n,m,sloz = 0;
int ploc[N][N],cnt,prost[N];
char x;

int squr(int x1,int x2,int y1,int y2){
    x2 = min(n-1,x2);y2 = min(m-1,y2);
    int ret = ploc[x2][y2];
    if(x1) ret -= ploc[x1-1][y2];
    if(y1) ret -= ploc[x2][y1-1];
    if(x1&&y1) ret += ploc[x1-1][y1-1];
    return ret;
}

int main(){
    memset(prost,1,sizeof(prost));
    for(int i = 2;i<N;i++){
        if(!prost[i]) continue;
        for(int j = 2;i*j<N;j++){
            prost[i * j] = 0;
        }
    }
    scanf("%d%d",&n,&m);
    x = getchar();
    for(int i = 0;i<n;i++){
        cnt = 0;
        for(int j = 0;j<m;j++){
            x = getchar();
            if(x - '0')
                cnt++;
            ploc[i][j] = cnt;
            if(i) ploc[i][j] += ploc[i-1][j];
        }
        x = getchar();
    }
    int sol = 0x3f3f3f3f;
    sloz = 0;
    for(int k = 2;k<=max(n,m);k++){
        if(!prost[k]) continue;
        int cur = 0;
        for(int i = 0;i<n;i+=k){
            for(int j = 0;j<m;j+=k){
                int ss = squr(i,i+k-1,j,j+k-1);
                cur += min(ss,k * k - ss);
                sloz++;
            }
        }
        sol = min(sol,cur);
    }
    printf("%d\n",sol);
}