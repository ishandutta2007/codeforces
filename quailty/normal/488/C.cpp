#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int y[3],m[3],c[3];
int main()
{
    for(int i=0;i<3;i++)
        scanf("%d",&y[i]);
    for(int i=0;i<3;i++)
        scanf("%d",&m[i]);
    for(int i=0;i<3;i++)
        scanf("%d",&c[i]);
    int res=INF;
    for(int atk=max(y[1],m[2]+1);atk<=200;atk++)
        for(int def=y[2];def<=100;def++)
        {
            int hp=max(0,m[1]-def)*((m[0]-1)/(atk-m[2])+1);
            res=min(res,c[0]*max(0,hp+1-y[0])+c[1]*(atk-y[1])+c[2]*(def-y[2]));
        }
    return 0*printf("%d",res);
}