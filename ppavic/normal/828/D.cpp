#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 3e5 + 500;
const int INF = 0x3f3f3f3f; // Ako mijena pazi na memset
const int MOD = 1e9 + 7;

vector < int > v[N];
vector < int > siz;

int n,k,cnt = 0;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = n-k+1;i<=n;i++){
        v[cnt].push_back(i);
        cnt++;
    }
    int i = 2,j = 0;
    while(i < n-k+1){
        v[j].push_back(i);
        j++;j %= cnt;
        i++;
    }
    for(int i = 0;i<cnt;i++){
        siz.push_back(v[i].size());
    }
    sort(siz.rbegin(),siz.rend());
    if(siz.size() == 1){
        printf("%d\n",(int)siz[0]);
    }
    else{
        printf("%d\n",(int)siz[0] +  (int)siz[1] );
    }
    for(int i = 0;i<cnt;i++){
        int lst = 1;
        for(int j = v[i].size()-1;j>=0;j--){
            printf("%d %d\n",lst,v[i][j]);
            lst = v[i][j];
        }
    }

}