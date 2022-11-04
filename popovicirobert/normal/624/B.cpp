#include <cstdio>
#include <algorithm>
int v[26];
using namespace std;
int main()
{
    long long s;
    int i,n,j,min;
    scanf("%d" ,&n);
    for(i=0;i<n;i++)
       scanf("%d" ,&v[i]);
    sort(v,v+n);
    i=n-1;
    s=0;
    min=1000000001;
    while(i>=0){
        if(v[i]<min){
            s+=v[i];
            min=v[i];
        }
        else{
           if(min>0)
              s+=min-1;
           min--;
        }
        i--;
    }
    printf("%I64d" ,s);
    return 0;
}