#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

unordered_map<int,int> vmax;
unordered_map<int,int> vmin;
int m,n;

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x < y) swap(x,y);
        if(!(vmax[x])) vmax[x] = y;
        else vmax[x] = max(vmax[x],y);
        if(!(vmin[x])) vmin[x] = y;
        else vmin[x] = min(vmin[x],y);
    }
    int najmanji = 0;
    int najvisi = 0;
    for(int i = 1;i<=n;i++){
        if(vmax[i]!=0){
            najmanji = i;
            break;
        }
    }
    int sol = 0;
    for(int i = n;i>=2;i--){
        if(najvisi == i) break;
        if(vmax[i]>najvisi) najvisi = vmax[i];
        if(i>najmanji && najmanji!=0) continue;
        sol++;
    }
    printf("%d",sol);

}