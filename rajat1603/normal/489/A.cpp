#include<stdio.h>
#include<algorithm>
using namespace std;
struct pairr{
    int first;
    int second;
};
pairr x[3001];
int main(){
    int n;
    scanf("%d",&n);
    int a[3001];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k=0;
    for(int i=0;i<n;i++){
        int minimum=10000000000;
        int index;
        for(int j=i+1;j<n;j++){
            if(a[j]<minimum){
                minimum=a[j];
                index=j;
            }
        }
        if(minimum<a[i]){
            x[k].first = i;
            x[k].second = index;
            k++;
            swap(a[i],a[index]);
        }
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++){
        printf("%d %d\n",x[i].first,x[i].second);
    }
}