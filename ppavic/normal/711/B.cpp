#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int llint;

int n;
llint last = -1;
llint magic[505][505];
int rx,ry;

int main() {
    scanf("%d",&n);
    if(n == 1){
        printf("1\n");
        return 0;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%I64d",&magic[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        llint csum = 0;
        bool broke = false;
        for(int j = 0;j<n;j++){
            if(magic[i][j] == 0){
                broke = true;
                rx = i;
                ry = j;
                break;
            }
            csum += magic[i][j];
        }
        if(broke) continue;
        if(last == -1) last = csum;
        if(last != csum){
            printf("-1\n");
            return 0;
        }
    }
    for(int j = 0;j<n;j++){
        llint csum = 0;
        bool broke = false;
        for(int i = 0;i<n;i++){
            if(rx == i && ry == j){
                broke = true;
                break;
            }
            csum += magic[i][j];
        }
        if(broke) continue;
        if(last != csum){
            printf("-1\n");
            return 0;
        }
    }
    //printf("CHECK1\n");
    llint csum = 0;
    for(int z = 0;z<n;z++){
        csum += magic[z][z];
        if(z == rx && z == ry) {csum = last;break;}
    }
    if(last != csum){
        printf("-1\n");
        return 0;
    }
    //printf("CHECK2\n");
    csum = 0;
    for(int z = 0;z<n;z++){
        csum += magic[n-z-1][z];
        if(n-z-1 == rx && z == ry) {csum = last;break;}
    }
    //printf("CHECK3\n");
    if(last != csum){
        printf("-1\n");
        return 0;
    }
    llint csum1 = 0;
    llint csum2 = 0;
    //printf("%d %d\n",rx,ry);
    for(int i = 0;i<n;i++){
        csum1 += magic[rx][i];
        csum2 += magic[i][ry];
    }
    if(csum1 == csum2){
        if(rx == ry){
            llint csum3 = 0;
            for(int i = 0;i<n;i++){
                csum3 += magic[i][i];
            }
            if(csum3 != csum1){
                printf("-1\n");
                return 0;
            }
        }
        if(rx == n-ry-1){
            llint csum3 = 0;
            for(int i = 0;i<n;i++){
                csum3 += magic[n-i-1][i];
            }
            if(csum3 != csum1){
                printf("-1\n");
                return 0;
            }
        }
        if(last -csum1 <= 0){
            printf("-1\n");
            return 0;
        }
        printf("%I64d\n",last - csum1);
    }
    else{
        printf("-1\n");
    }
}