#include<iostream>
using namespace std;
int main(){
    int x,a[10]={0},b=0,i;
    for(i=0;i<6;i++){
        cin>>x;
        a[x]++;
    }
    for(i=0;i<10;i++){
        if(a[i]>=4){
           b=1;//elephant
        }
    }
    if(b==1){
        for(i=0;i<10;i++){
            if(a[i]==1){
                b=2;
                break;
            }
        }
    }
    if(b==0){
        cout<<"Alien";
    }
    if(b==1){
        cout<<"Elephant";
    }
    if(b==2){
        cout<<"Bear";
    }
}