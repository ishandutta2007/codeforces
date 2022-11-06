#include <cstdio>

int data[120];

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) scanf("%1d",data+i);
    data[0]++;
    int cnt = 1;
    for(i=0;i<n;i++){
        if(data[i]==2){
            cnt++;
            data[i+1]++;
        }
    }
    if(data[n]==1) cnt--;
    printf("%d\n",cnt);
    return 0;
}