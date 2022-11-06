#include <cstdio>

char ans[100010];

int main()
{
    char data[100010];
    scanf("%s",data);
    for(int i=0; data[i]; ++i){
        if(data[i] == 'a'){
            ans[i]='a';
        } else {
            int j;
            for(j=i; data[j] && data[j]!='a'; ++j){
                ans[j]=data[j]-1;
            }
            for(;data[j];++j) ans[j]=data[j];
            puts(ans);
            return 0;
        }
    }
    for(int i=0;; ++i) if(!data[i]){
        ans[i-1]='z';
        break;
    }
    puts(ans);
    return 0;
}