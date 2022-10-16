#include <cstdio>
#include <vector>

using namespace std;

const int N = 105;

int n,a[N];
vector <pair <int,int> > sol;
int pref[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    pref[0] = a[0];
    for(int i = 1;i<n;i++){
        pref[i] = a[i] + pref[i-1];
    }
    if(pref[n-1] != 0){
        printf("YES\n");
        printf("1\n");
        printf("1 %d\n",n);
        return 0;
    }
    int j = 0;
    while(pref[j] == 0 || pref[n-1]-pref[j] == 0) {
        j++;
        if(j == n) break;
    }
    if(j == n){
        printf("NO\n");
        return 0;
    }
    else{
        printf("YES\n");
        printf("2\n");
        printf("1 %d\n",j+1);
        printf("%d %d\n",j+2,n);
        return 0;
    }
}