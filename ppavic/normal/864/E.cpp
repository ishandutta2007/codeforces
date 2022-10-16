#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct obj{
    int d,t,p,i;
};

bool cmp(obj A,obj B){
    return A.d < B.d;
}

const int N = 105;
const int T = 2005;

vector < obj > v;

int dp[N][T],n,rek[N][T];

int f(int i,int j){
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ret = 0;
    if(j + v[i].t < v[i].d){
        ret = f(i+1,j+v[i].t)+v[i].p;
        rek[i][j] = 1;
    }
    if(f(i+1,j) > ret){
        rek[i][j] = 0;
        ret = f(i+1,j);
    }
    return dp[i][j] = ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        obj nw;nw.t = a;nw.d = b;nw.p = c;nw.i = i+1;
        v.push_back(nw);
    }
    sort(v.begin(),v.end(),cmp);
    printf("%d\n",f(0,0));
    int ct = 0;
    vector < int > sol;
    for(int i = 0;i<n;i++){
        if(rek[i][ct]){
            sol.push_back(v[i].i);
            ct+=v[i].t;
        }
    }
    printf("%d\n",sol.size());
    for(int i = 0;i<sol.size();i++)
        printf("%d ",sol[i]);
    printf("\n");

}