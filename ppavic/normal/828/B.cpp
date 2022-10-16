#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f; // Ako mijena pazi na memset
const int MOD = 1e9 + 7;

string p[N];
int n,m,cnt = 0;
int minx = INF,maxx = -1,miny = INF,maxy = -1,str;

int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> p[i];
        for(int j = 0;j<m;j++){
            if(p[i][j] == 'B'){
                maxx = max(i,maxx);
                maxy = max(j,maxy);
                minx = min(i,minx);
                miny = min(j,miny);
                cnt++;
            }
        }
    }
    //printf("%d %d %d %d\n",maxx,minx,maxy,miny);
    int str = max(maxx-minx + 1,maxy-miny + 1);
    int toadd = str * str - cnt;
    if(cnt == 0){
        printf("1\n");
        return 0;
    }
    else if(str  > n || str > m){
        printf("-1\n");
        return 0;
    }
    else{
        printf("%d\n",toadd);
        return 0;
    }

}