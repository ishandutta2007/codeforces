#include <cstdio>
#include <algorithm>

using namespace std;

int data[200010];

int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    int i;
    for(i=0;i<2*n;++i) scanf("%d",data+i);
    sort(data,data+2*n);
    printf("%f\n",min(w*1.0,min(data[0]*1.0, data[n]*0.5)*n*3));
    return 0;
}