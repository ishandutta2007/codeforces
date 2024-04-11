#include <cstdio>
#include <iostream>
#include <vector>

char c;
int d;
int posx[8] = {0,0,1,-1,1,1,-1,-1};
int posy[8] = {1,-1,0,0,1,-1,1,-1};

using namespace std;

int main(){
    scanf("%c%d",&c,&d);
    int sol = 0;
    for(int i = 0;i<8;i++){
        if(c+ posx[i] <='h' && c+ posx[i] >='a' && d+posy[i] <=8 && d+posy[i] >= 1) sol++;
    }
    printf("%d\n",sol);
}