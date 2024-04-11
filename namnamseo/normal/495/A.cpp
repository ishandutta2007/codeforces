#include <cstdio>

int n;

bool table[10][7]={
    1,1,1,0,1,1,1,
    0,0,1,0,0,1,0,
    1,0,1,1,1,0,1,
    1,0,1,1,0,1,1,
    0,1,1,1,0,1,0,
    1,1,0,1,0,1,1,
    1,1,0,1,1,1,1,
    1,0,1,0,0,1,0,
    1,1,1,1,1,1,1,
    1,1,1,1,0,1,1
};

int count(int x){
    int i,j,ret=0;
    for(i=0;i<10;++i){
        for(j=0;j<7;++j){
            if(!table[i][j] && table[x][j]) break;
        }
        if(j==7) ++ret;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",count(n/10)*count(n%10));
    return 0;
}