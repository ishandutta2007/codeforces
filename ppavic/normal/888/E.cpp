#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 40;

vector < int > v[2];

int a[N],n,m,sol;

void brut(int l,int r,int ind){
    int siz = r - l + 1;
    for(int i = 0;i<(1<<siz);i++){
        int sum = 0;
        for(int j = 0;j<siz;j++){
            if(!((1<<j)&i)) continue;
            sum = (sum + a[j+l]) % m;
        }
        sol = max(sol,sum);
        v[ind].push_back(sum);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    brut(0,n/2-1,0);
    brut(n/2,n-1,1);
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    for(int i = 0;i<v[0].size();i++){
        int x = lower_bound(v[1].begin(),v[1].end(),m - v[0][i]) - v[1].begin();
        x = (x + v[1].size() - 1) % v[1].size();
        sol = max(sol, (v[0][i] + v[1][x]) % m);
        sol = max(sol, (v[1][v[1].size()-1] + v[0][i]) % m);
    }
    printf("%d\n",sol);
}