#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool b[400400];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<=2*n;i++) b[i]=0;
        for (int i=0;i<n;i++){
            int tmp;
            scanf("%d", &tmp);
            b[tmp]=1;
        }
        int cnt=0;
        int ansmin=0, ansmax=0;
        for (int i=1;i<=2*n;i++){
            if (!cnt && b[i]){
                ansmin++;
                //printf("%d ", i);
            }
            else if (b[i]){
                cnt--;
            }
            else{
                cnt++;
            }
        }
        cnt=0;
        for (int i=2*n;i>0;i--){
            if (!cnt && b[i]) ansmax++;
            else if (b[i]) cnt--;
            else cnt++;
        }
        ansmax=n-ansmax;
        //printf("%d %d\n", ansmin, ansmax);
        printf("%d\n", ansmax-ansmin+1);
    }
    return 0;
}