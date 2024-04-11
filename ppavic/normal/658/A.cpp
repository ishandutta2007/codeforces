#include <cstdio>
#include <algorithm>

using namespace std;

int t[55],p[55],x,c;

int main(){
    scanf("%d %d",&x,&c);
    for(int i = 0;i<x;i++)
        scanf("%d",&p[i]);
    for(int i = 0;i<x;i++)
        scanf("%d",&t[i]);
    int t1 = 0;
    int t2 = 0;
    int s1 = 0;
    int s2 = 0;
    int i = 0;
    int j = x-1;
    for(;i<x;i++,j--){
    t1+=t[i];
        s1+=max(0,p[i]-c*t1);
        t2+=t[j];
        s2+=max(0,p[j]-c*t2);

    }
    if(s1>s2){
        printf("Limak");
    }
    else if(s2>s1){
        printf("Radewoosh");
    }
    else{
        printf("Tie");
    }

}