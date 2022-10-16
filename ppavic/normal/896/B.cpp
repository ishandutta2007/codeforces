#include <cstdio>
#include <cstring>

using namespace std;

int a[1005],c,n,m,notwin = 1;

void add(int x){
    if(x > c/2){
        int st = n - 1;
        while(st > 0 && a[st] >= x) st--;
        printf("%d\n",st+1);
        a[st] = x;
    }
    else{
        int st = 0;
        while(st < n -1 && a[st] <= x && a[st] != -1) st++;
        printf("%d\n",st+1);
        a[st] = x;
    }
    notwin = 0;
    for(int i = 1;i<n;i++){
        if(a[i-1] > a[i] || a[i] == -1 || a[i-1] == -1) notwin = 1;
    }
}

int main(){
    memset(a, -1, sizeof(a));
    scanf("%d%d%d",&n,&m,&c);
    for(int i = 0;i<m && notwin;i++){
        int x;scanf("%d",&x);
        add(x);fflush(stdout);
    }
}