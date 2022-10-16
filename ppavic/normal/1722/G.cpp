#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 500;

int A[N], xr[2];
unordered_map < int, int > bio;

int raand(){
    int ret = rand() * rand() * rand();
    return ret > 0 ? ret : -ret;
}

bool solve(int n){
    xr[0] = 0, xr[1] = 0;
    bio.clear();
    for(int i = 0;i + 1 < n;i++){
        int x = raand();
        while(bio[x]) x = raand();
        bio[x] = 1;
        A[i] = x;
        xr[i % 2] ^= A[i];
    }
    if(bio[xr[0] ^ xr[1]])
        return false;
    A[n - 1] = xr[0] ^ xr[1];
    return true;
}

int main(){
    srand(69);
    int T; scanf("%d", &T);
    for(;T--;) {
        int n; scanf("%d", &n);
        for(;!solve(n););
        for(int i = 0;i < n;i++)
            printf("%d ", A[i]);
        printf("\n");
    }
}