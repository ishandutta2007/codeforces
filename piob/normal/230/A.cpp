#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, s;
pair<int, int> T[1024];

int main(){
    scanf("%d %d", &s, &n);
    FWD(i,0,n){
        scanf("%d %d", &T[i].first, &T[i].second);
    }
    sort(T, T+n);
    FWD(i,0,n){
        if(s > T[i].first)
            s += T[i].second;
        else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}