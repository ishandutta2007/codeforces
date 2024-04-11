#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const char res[7][4]=
{
    "0/1","1/6","1/3","1/2","2/3","5/6","1/1"
};
int main()
{
    int y,w;
    scanf("%d%d",&y,&w);
    printf("%s",res[6-max(y,w)+1]);
    return 0;
}