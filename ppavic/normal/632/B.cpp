#include <cstdio>
#include <iostream>

typedef long long int lii;

using namespace std;

int num[500005];
char a[500005];
lii a1[500005];
lii a2[500005];
lii b1[500005];
lii b2[500005];
lii n,m=-1;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&num[i]);
    }
    cin >> a;
    for(int i = 0;i<n;i++){
        if(a[i]=='A'){
            if(i==0){
                a1[i]=num[i];
            }
            else{
                a1[i] = a1[i-1]+num[i];
                b1[i] = b1[i-1];
            }
        }
        else{
            if(i==0){
                b1[i]=num[i];
            }
            else{
                a1[i]=a1[i-1];
                b1[i] = b1[i-1]+num[i];
            }
        }
    }
    //return 0;
    for(int i = n-1;i>=0;i--){
        if(a[i]=='A'){
            a2[i] = a2[i+1]+num[i];
            b2[i] = b2[i+1];
        }
        else{
            a2[i]=a2[i+1];
            b2[i] = b2[i+1]+num[i];
        }
    }
    /*
    printf("A1\n");
    for(int i = 0;i<n;i++) printf("%d ",a1[i]);
    printf("\n");
    printf("A2\n");
    for(int i = 0;i<n;i++) printf("%d ",a2[i]);
    printf("\n");
    printf("B1\n");
    for(int i = 0;i<n;i++) printf("%d ",b1[i]);
    printf("\n");
    printf("B2\n");
    for(int i = 0;i<n;i++) printf("%d ",b2[i]);
    printf("\n");*/
    for(int i = 0;i<n;i++){
        if(a1[i]+b2[i+1]>m)
            m=a1[i]+b2[i+1];
        if(b1[i]+a2[i+1]>m)
            m=b1[i]+a2[i+1];
    }
    printf("%I64d",m);



}