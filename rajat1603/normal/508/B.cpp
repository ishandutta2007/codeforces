#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
#define pb push_back
#define mp make_pair
int main(){
    char a[123321]={NULL};
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n-1;i++){
        if((a[i]-'0')%2==0&&a[i]<a[n-1]){
            char temp=a[n-1];
            a[n-1]=a[i];
            a[i]=temp;
            printf("%s",a);
            return 0;
        }
    }
    for(int i=n-2;i>=0;i--){
        if((a[i]-'0')%2==0){
            char temp=a[n-1];
            a[n-1]=a[i];
            a[i]=temp;
            printf("%s",a);
            return 0;
        }
    }
    printf("-1");
}