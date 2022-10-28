#include<bits/stdc++.h>
using namespace std;
int c[257]={0};
bool done[200001]={0};
int main(){
    char a[200001]={NULL};
    char b[200001]={NULL};
    scanf("%s",a);
    scanf("%s",b);
    int n=strlen(a);
    int m=strlen(b);
    for(int i=0;i<m;i++){
        c[b[i]]++;
    }
    int yay=0;
    int whoops=0;
    for(int i=0;i<n;i++){
        char t=a[i];   
        if(c[t]>0){
            yay++;
            c[t]--;
            done[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(!done[i]){
            char t=a[i];
            if(t>='a'){
                if(c[t-32]>0){
                    whoops++;
                    c[t-32]--;
                }
            }
            else{
                if(c[t+32]>0){
                    whoops++;
                    c[t+32]--;
                }
            }
        }
    }
    printf("%d %d",yay,whoops);
}