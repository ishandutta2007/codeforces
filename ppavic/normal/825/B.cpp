#include <cstdio>
#include <algorithm>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

int px[8] = {0,0,1,-1,1,-1,-1,1};
int py[8] = {1,-1,0,0,1,-1,1,-1};

const int N = 15;
const int INF = 0x3f3f3f3f;
const int off = 1<<18;
const int MOD = 1e9 + 7;

int sol = 0;

string p[N];


int main(){
    for(int i = 0;i<10;i++)
        cin >> p[i];

    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(p[i][j] != '.') continue;
            int sx,sy,cnt = 0;
            for(int k = 0;k<8;k+=2){
                cnt = 0;
                for(int u = 0;u<2;u++){
                    sx = i + px[k+u];sy = j + py[k+u];
                    while(min(sx,sy) >= 0 && max(sx,sy) < 10 && p[sx][sy] == 'X'){
                        sx += px[k+u];
                        sy += py[k+u];
                        cnt++;
                    }
                }
                sol = max(cnt + 1,sol);
            }

        }
    }
    if(sol >= 5){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}