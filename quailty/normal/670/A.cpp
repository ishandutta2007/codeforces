#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    int res[2]={0,0};
    for(int i=0;i<n;i++)
    {
        if(i%7>=5)res[0]++;
        if(i%7<=1)res[1]++;
    }
    printf("%d %d\n",res[0],res[1]);
    return 0;
}