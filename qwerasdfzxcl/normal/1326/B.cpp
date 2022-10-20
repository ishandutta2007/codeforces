#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int tmp=0;
    for (int i=0;i<n;i++){
        int tmp2;
        scanf("%d", &tmp2);
        if (tmp2>=0){
            tmp += tmp2;
            printf("%d ", tmp);
        }
        else printf("%d ", tmp+tmp2);
    }
    return 0;
}