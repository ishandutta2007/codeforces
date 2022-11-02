#include <bits/stdc++.h>
#define pb push_back
#define maxn 100100
using namespace std;

#define t 25

char ans[2*t][2*t];

int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("50 50\n");
    for(int i=0;i<2*t;i++)
        for(int j=0;j<2*t;j++){
            if(i < t && j < t) ans[i][j] = 'A';
            if(i < t  && j >= t) ans[i][j] = 'B';
            if(i >= t && j < t) ans[i][j] = 'C';
            if(i >= t && j >= t) ans[i][j] = 'D';
        }
        
    a--, b--, c--, d--;
    
    int x = 0, y = 0;
    while(b--){
        ans[x][y] = 'B';
        y += 2;
        if(y == t-1){
            y = 0;
            x += 2;
        }
    }
    x = 0, y = t+1;
    while(c--){
        ans[x][y] = 'C';
        y += 2;
        if(y >= 2*t){
            y = t+1;
            x += 2;
        }
    }
    
    x = t+1, y = 0;
    while(d--){
        ans[x][y] = 'D';
        y += 2;
        if(y >= t-1){
            y = 0;
            x += 2;
        }
    }
    
    x = 2*t-1, y = 2*t-1;
    while(a--){
        ans[x][y] = 'A';
        y -= 2;
        if(y <= t+1){
            y = 2*t-1;
            x -= 2;
        }
    }
    
    for(int i=0;i<2*t;i++){
        for(int j=0;j<2*t;j++)
            printf("%c",ans[i][j]);
        printf("\n");
    }
        
}