#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char input[500];
char tmp[500]={0};
char cop[7]="trygub";

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for (int i=0;i<500;i++) tmp[i]=0;
        int n;
        scanf("%d", &n);
        scanf("%s", input);
        int j=0, k=0;
        for (int i=0;i<n;i++){
            if (input[i]=='b'){
                j++;
                continue;
            }
            tmp[k]=input[i];
            k++;
        }
        for (int i=0;i<j;i++) printf("b");
        printf("%s\n", tmp);
    }
    return 0;
}