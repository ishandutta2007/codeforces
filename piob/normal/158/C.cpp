#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a;scanf("%d",&a);++a;while(--a)
#define PLL pair<long long, long long>
#define x first
#define y second

using namespace std;

int n, k;
char cmd[8];
char path[256];
string dir;
vector<string> V;

void move(){
    if(path[k] == '/')
        ++k;
    dir.clear();
    while(path[k] != 0 && path[k] != '/')
        dir += path[k++];
    if(dir[0] == '.')
        V.pop_back();
    else
        V.push_back(dir);
}

void print(){
    FE(d,V)
        printf("/%s", d->c_str());
    printf("/\n");
}

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%s", cmd);
        if(cmd[0] == 'c'){
            scanf("%s", path);
            k = 0;
            if(path[0] == '/'){
                V.clear();
                k = 1;
            }
            while(path[k] != 0)
                move();
        }else
            print();
    }
    return 0;
}