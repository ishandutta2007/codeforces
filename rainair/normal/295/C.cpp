#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 50+5;
const int ha = 1e9 + 7;

LL C[MAXN][MAXN],f[MAXN][MAXN][MAXN],dis[MAXN][MAXN][MAXN];

struct Node{
    int i,j,k; // 50 100  
    Node(){}
    Node(int i,int j,int k) : i(i),j(j),k(k) {}
};
std::queue<Node> q;
int n,k,n0,n1;
int a[MAXN];
int main(){
    FOR(i,0,MAXN-1) C[i][0] = 1,C[i][1] = i;
    FOR(i,1,MAXN-1){
        FOR(j,2,i) C[i][j] = (C[i-1][j]+C[i-1][j-1])%ha;
    }
    scanf("%d%d",&n,&k);FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) if(a[i] == 50) n0++;n1 = n-n0;CLR(dis,-1);
    q.push(Node(n0,n1,0));dis[n0][n1][0] = 0;f[n0][n1][0] = 1;
    while(!q.empty()){
        Node v = q.front();q.pop();
        int x = v.i,y = v.j,z = v.k;
        FOR(i,0,x){
            if(i*50 > k) break;
            FOR(j,0,y){
                if(i*50+j*100 > k) break;
                if(!(i+j)) continue;
                int xx = n0-x+i,yy = n1-y+j,zz = z^1;
                if(dis[xx][yy][zz] == -1){
                    (dis[xx][yy][zz] = dis[x][y][z] + 1) %= ha;
                    f[xx][yy][zz] = 1ll*f[x][y][z]*C[x][i]%ha*C[y][j]%ha;
                    q.push(Node(xx,yy,zz));
                }
                else if(dis[xx][yy][zz] == dis[x][y][z] + 1){
                    (f[xx][yy][zz] += 1ll*f[x][y][z]*C[x][i]%ha*C[y][j]%ha) %= ha;
                }
            }
        }
    }
    printf("%lld\n%lld\n",dis[n0][n1][1]%ha,f[n0][n1][1]%ha);
    return 0;
}