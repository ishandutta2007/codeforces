#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int matrix[400];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        ll X=0;
        int c1=0, c2=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                scanf("%d", &matrix[i*m+j]);
                X += abs(matrix[i*m+j]);
                if (matrix[i*m+j]<0) c1++;
                if (!matrix[i*m+j]) c2++;
                matrix[i*m+j]=abs(matrix[i*m+j]);
            }
        }
        if (c2){
            printf("%lld\n", X);
            continue;
        }
        else if (c1%2==0){
            printf("%lld\n", X);
        }
        else{
            sort(matrix, matrix+n*m);
            printf("%lld\n", X-2*matrix[0]);
        }
    }
    return 0;
}