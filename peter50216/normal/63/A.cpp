#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int n[1000];
char nam[1000][100];
bool cmp(int a,int b){
    if(n[a]!=n[b])return n[a]<n[b];
    return a<b;
}
int id[1000];
char t[1000];
int main(){
    int nn,i;
    scanf("%d",&nn);
    for(i=0;i<nn;i++){
    id[i]=i;
    scanf("%s",nam[i]);
    scanf("%s",t);
    if(t[0]=='r')n[i]=1;
    else if(t[0]=='w'||t[1]=='h')n[i]=2;
    else if(t[0]=='m')n[i]=3;
    else n[i]=4;
    }
    sort(id,id+nn,cmp);
    for(i=0;i<nn;i++)puts(nam[id[i]]);
}