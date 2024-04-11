#include <bits/stdc++.h>
#define pb push_back
#define maxn 100100
using namespace std;

char str[maxn];

int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    scanf(" %s",str);
    int ok = 0;
    for(int i=0;i<t;i++){
        int q0 = 0, q1 = 0, qp = 0;
        for(int j=i;j<n;j+=t){
            if(str[j] == '0') q0++;
            if(str[j] == '1') q1++;
            if(str[j] == '.') qp++;
        }
        if(q0 > 0 && q1 > 0)
            ok = 1;
        else if(q0 > 0 && qp){
            for(int j=i;j<n;j+=t)
                if(str[j] == '.') str[j] = '1';
            ok = 1;
        }
        else if(q1 > 0 && qp){
                for(int j=i;j<n;j+=t)
                    if(str[j] == '.') str[j] = '0';
                ok = 1;
        }
        else if(qp > 1){
            int foi = 0;
            for(int j=i;j<n;j+=t)
                if(str[j] == '.'){
                    if(!foi){
                        foi = 1;
                        str[j] = '0';
                    }
                    else str[j] = '1';
                ok = 1;
                }
        }
        
    }
    
    if(!ok){
        printf("No\n");
        return 0;
    }
    for(int i=0;i<n;i++)
        if(str[i] == '.') str[i] = '0';
    printf("%s\n",str);
}