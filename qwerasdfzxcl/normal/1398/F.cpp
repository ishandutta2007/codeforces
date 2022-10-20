#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[1001000];
int L[1001000], R[1001000];

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", a+1);

    ///get array R
    int val = -1, prv = 1, prvq = -1;
    for (int i=1;i<=n;i++){
        if (a[i]=='?'){
            if (a[i-1]!='?') prvq = i;
            continue;
        }
        if (val==-1){
            prvq = -1;
            val = a[i] - '0';
            continue;
        }
        if (val==a[i]-'0'){
            prvq = -1;
            continue;
        }

        for (int j=prv;j<i;j++) R[j] = i;

        if (prvq!=-1) prv = prvq;
        else prv = i;
        prvq = -1;
        val = a[i]-'0';
    }
    for (int j=prv;j<=n;j++) R[j] = n+1;

    ///get array L
    val = -1, prv = n, prvq = -1;
    for (int i=n;i;i--){
        if (a[i]=='?'){
            if (a[i+1]!='?') prvq = i;
            continue;
        }
        if (val==-1){
            prvq = -1;
            val = a[i]-'0';
            continue;
        }
        if (val==a[i]-'0'){
            prvq = -1;
            continue;
        }

        for (int j=prv;j>i;j--) L[j] = i;
        if (prvq!=-1) prv = prvq;
        else prv = i;
        prvq = -1;
        val = a[i]-'0';
    }
    for (int j=prv;j;j--) L[j] = 0;

    /*for (int i=1;i<=n;i++) printf("%d ", R[i]);
    printf("\n");
    for (int i=1;i<=n;i++) printf("%d ", L[i]);
    printf("\n");*/

    ///calc ans
    for (int z=1;z<=n;z++){
        int pt = 1, ans = 0, cnt = 0;
        while(pt<=n){
            cnt++;
            if (R[pt]-pt >= z) {
                pt += z;
                ans++;
            }
            else{
                pt += z-1;
                if (pt>n) break;
                assert(pt-L[pt]<z);
                pt = L[pt] + 1;
            }
        }
        printf("%d ", ans);
    }
    return 0;
}