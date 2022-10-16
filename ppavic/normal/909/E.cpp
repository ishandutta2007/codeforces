#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1e6 + 500;

queue < int > q0;
queue < int > q1;

int n,m;
int lf[N];
vector < int > v[N];
int lst = 1,in[N],sol;

void add(int x){
    if(!lf[x]) q1.push(x);
    else      q0.push(x);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++)
        scanf("%d",lf+i);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d%d",&y,&x);
        v[x].push_back(y);
        in[y]++;
    }
    for(int i = 0;i<n;i++){
        if(in[i] == 0) add(i);
    }
    while((!q0.empty()) || (!q1.empty())){
        while(!q1.empty()){
            int x = q1.front();
            for(int i = 0;i<v[x].size();i++){
                in[v[x][i]]--;
                if(in[v[x][i]] == 0) add(v[x][i]);
            }
            q1.pop();
        }
        if(!q0.empty()) sol++;
        while(!q0.empty()){
            int x = q0.front();
            for(int i = 0;i<v[x].size();i++){
                in[v[x][i]]--;
                if(in[v[x][i]] == 0) add(v[x][i]);
            }
            q0.pop();
        }
    }
    printf("%d\n",sol);
}