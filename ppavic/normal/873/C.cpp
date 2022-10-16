#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 305;
const int INF = 0x3f3f3f3f;

int n,k,m;
int mat[N][N];
int pref[N][N];
int sol = 0;
int pot = 0;

int get(int x,int y,int z){
    int ret = pref[y][z];
    if(x) ret -= pref[x-1][z];
    return ret;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(int j = 0;j<m;j++){
        pref[0][j] = mat[0][j];
        for(int i = 1;i<2*n;i++)
            pref[i][j] += pref[i-1][j] + mat[i][j];
    }
    for(int j = 0;j<m;j++){
        int toadd = 0;
        int bst = 0;
        for(int i = 0;i<n;i++){
            if(mat[i][j]){
                bst = max(bst, get(i , i + k - 1 , j));
            }
        }
        int md = 0;
        for(int i = 0;i<n;i++){
            if(mat[i][j] && get(i , i + k - 1 , j) == bst){
                sol += bst;
                pot += md;
                break;
            }
            if(mat[i][j]) md++;
        }
    }
    printf("%d %d\n",sol,pot);
}